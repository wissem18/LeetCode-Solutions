/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    // 1. Find the index of the peak element
    int l = 1;
    int r = n - 2;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int peakIndex = l;

    // 2. Search in the strictly increasing part of the array
    l = 0;
    r = peakIndex;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    // Check if the target is present in the strictly increasing part
    if (mountainArr.get(l) == target) {
        return l;
    }

    // 3. Otherwise, search in the strictly decreasing part
    l = peakIndex + 1;
    r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mountainArr.get(mid) > target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    // Check if the target is present in the strictly decreasing part
    if (mountainArr.get(l) == target) {
        return l;
    }

    // Target is not present in the mountain array
    return -1;
}
};