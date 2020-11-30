package com.learn_java;

import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

/**
 * 1. Doesn't support adding null keys
 * 2. Doesn't support adding null values
 * 3. Doesn't support fail-fast iterator
 */
public class CustomHashMap<K, V> extends AbstractMap<K, V> {
    private static final int INIT_SIZE = 16;
    private List<Node> buckets;
    private final double loadFactor;
    private int valSize;
    private int keySize;
    private long changeCount = 0; // for implementing fail-fast iterator

    public CustomHashMap(int size) {
        this.buckets = new ArrayList<>(size);
        loadFactor = 0.75;
        valSize = 0;
        keySize = size;
        initBucket();
    }

    public CustomHashMap() {
        this(INIT_SIZE);
    }

    private class Node {
        K key;
        V val;
        Node next;

        public Node(K key, V val, Node node) {
            this.key = key;
            this.val = val;
            this.next = node;
        }

        public Node(K key, V val) {
            this(key, val, null);
        }
        K getKey() { return key; }
        V getValue() { return val; }
    }


    @Override
    public V put(K k, V v) {
        rehashIfNeeded();
        int bucketIdx = getIdx(k);
        Node node = buckets.get(bucketIdx);
        while (node != null) {
            if (node.key.equals(k)) {
                V oldVal = node.val;
                node.val = v;
                return oldVal;
            }
            node = node.next;
        }
        Node newNode = new Node(k, v, buckets.get(bucketIdx));
        buckets.set(bucketIdx, newNode);
        valSize++;
        changeCount++;
        return null;
    }

    @Override
    public V get(Object key) {
        int keyIdx = getIdx(key);
        Node node = buckets.get(keyIdx);
        return iterateAndGetIfPresent(node, n -> n.key.equals(key));
    }

    @Override
    public boolean containsKey(Object key) {
        return get(key) != null;
    }

    @Override
    public boolean containsValue(Object val) {
        return buckets
                .stream()
                .anyMatch(node -> iterateAndGetIfPresent(node, it -> it.getValue().equals(val)) != null);
    }

    @Override
    public V remove(Object key) {
        int idx = getIdx(key);
        Node currNode = buckets.get(idx);
        Node prev = null;
        while (currNode != null) {
            if (currNode.key.equals(key)) {
                valSize--;
                V oldVal = currNode.getValue();
                if (prev == null) { // node is first element
                    buckets.set(idx, null);
                } else {
                    prev.next = currNode.next;
                }
                return oldVal;
            }
            prev = currNode;
            currNode = currNode.next;
        }
        changeCount++;
        return null;
    }

    @Override
    public void clear() {
        buckets.clear();
        buckets = new ArrayList<>(INIT_SIZE);

    }

    @Override
    public Set<Entry<K, V>> entrySet() {
        long expectedChangeCount = changeCount;
        return buckets
                .stream()
                .map(node -> nodeToSet(node, expectedChangeCount))
                .flatMap(Collection::stream)
                .collect(Collectors.toSet());
    }

    private Set<Entry<K, V>> nodeToSet(Node node, long expectedChangeCount) {
        if (changeCount != expectedChangeCount) {
            throw new ConcurrentModificationException();
        }
        Set<Entry<K, V>> set = new HashSet<>();
        while (node != null) {
            set.add(new AbstractMap.SimpleImmutableEntry<K, V>(node.getKey(), node.getValue()));
            node = node.next;
        }
        return set;
    }

    private V iterateAndGetIfPresent(Node node, Predicate<Node> nodeCmp) {
        while (node != null) {
            if (nodeCmp.test(node)) {
                return node.val;
            }
            node = node.next;
        }
        return null;
    }

    private int getIdx(Object key) {
        return hash(Math.abs(key.hashCode())) % keySize;
    }

    private int hash(int hashCode) {
        return hashCode ^ 31;
    }

    private void rehashIfNeeded() {
        double currentLoadFactor = (double) valSize / buckets.size();
        System.out.println(valSize + " " + buckets.size() + " " + currentLoadFactor + " " + loadFactor);
        if (currentLoadFactor > loadFactor) {
            System.out.println("rehashed");
            List<Node> oldBuckets = buckets;
            buckets = new ArrayList<>(keySize * 2);
            keySize = keySize * 2;
            initBucket();
            oldBuckets
                    .stream()
                    .filter(Objects::nonNull)
                    .forEach(node -> {
                        int newIdx = getIdx(node.key);
                        buckets.set(newIdx, node);
                    });
        }
    }

    @Override
    public String toString() {
        StringJoiner sj = new StringJoiner(", ", "{", "}");
        for (Node node : buckets) {
            while (node != null) {
                sj.add(node.key + "=" + node.val);
                node = node.next;
            }
        }
        return sj.toString();
    }

    private void initBucket() {
        for (int i = 0; i < keySize; i++) {
            buckets.add(null);
        }
    }

    //run main method
    public static void main(String...args) {
        Map<Integer, String> map = new CustomHashMap<>(1);
        map.put(1, "John");
        map.put(12, "Sweety");
        map.put(1010, "Joshua");
        map.put(-898, "Smith");
        map.put(-898, "Smith");
        map.put(-898, "Hello");
        map.put(9000, "map 1");
        map.put(10000, "map 2");
        map.put(10001, "map 2");
        map.put(10002, "map 2");
        map.put(10003, "map 2");
        //map.put(12, "Sweet");
        System.out.println(map);
        System.out.println(map.size());

        map.remove(10);
        System.out.println(map);
        map.remove(12);
        System.out.println(map);

        for (Map.Entry<Integer, String> entry: map.entrySet()) {
            System.out.println(entry.getKey() + " => " + entry.getValue());
            map.put(101011010, "hello"); // should throw concurrent-modification exception
        }
    }
}