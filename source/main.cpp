#include <iostream>
#include <list>
#include <memory>
#include <array>

// Forward iterator class for merged sorted lists using std::list
class MergedListsIterator
{
private:
    // Fixed number of lists (3 as per problem requirements)
    static constexpr size_t NUM_LISTS = 3;

    // Store iterators for each of the three input lists
    // Using std::array for fixed-size storage and random access
    std::array<std::list<int>::const_iterator, NUM_LISTS> iterators;

    // Store end iterators for each list to check boundaries
    std::array<std::list<int>::const_iterator, NUM_LISTS> ends;

public:
    // Constructor takes three sorted std::list references
    // Using const references to avoid copying the input lists
    MergedListsIterator(const std::list<int>& list1, const std::list<int>& list2, const std::list<int>& list3)
    {
        // Initialize iterators array with begin() positions of all three lists
        iterators = {list1.cbegin(), list2.cbegin(), list3.cbegin()};

        // Initialize ends array with end() positions for boundary checking
        ends = {list1.cend(), list2.cend(), list3.cend()};
    }

    // Returns true if at least one list has remaining elements
    // O(1) time complexity since NUM_LISTS is constant (3)
    bool HasNext() const
    {
        // Check if any iterator hasn't reached its corresponding end
        for (size_t i = 0; i < NUM_LISTS; ++i)
        {
            if (iterators[i] != ends[i])
            {
                return true; // Found at least one list with elements remaining
            }
        }
        return false; // All lists exhausted
    }

    // Returns the next smallest element from merged sequence
    // Advances only the iterator that provided the minimum value
    int GetNext()
    {
        // Safety check - don't allow calling GetNext() when no elements remain
        if (!HasNext())
        {
            throw std::out_of_range("No more elements available");
        }

        // Find index of list with smallest current head value
        // Initialize with first valid iterator
        size_t min_idx = -1; // Use an invalid index to start
        int min_val;

        // Find the first available list to initialize min_val and min_idx
        for (size_t i = 0; i < NUM_LISTS; ++i)
        {
            if (iterators[i] != ends[i])
            {
                min_idx = i;
                min_val = *iterators[i];
                break;
            }
        }

        // Compare with other lists' current heads (skip exhausted lists)
        // Start from min_idx + 1 since we already have the value from min_idx
        for (size_t i = min_idx + 1; i < NUM_LISTS; ++i)
        {
            if (iterators[i] != ends[i])
            { // Only compare non-exhausted lists
                int current_val = *iterators[i];
                if (current_val < min_val)
                {
                    // Found smaller value - update minimum
                    min_val = current_val;
                    min_idx = i;
                }
            }
        }

        // Advance ONLY the iterator from the list that provided minimum value
        // This maintains sorted order since lists remain sorted and disjoint
        ++iterators[min_idx];

        return min_val; // Return the smallest value found
    }
};

// Test function demonstrating iterator usage with example data
void TestMergedIterator()
{
    // Example input: three disjoint sorted lists as specified in problem
    std::list<int> list1 = {1, 8, 15, 16, 35};
    std::list<int> list2 = {2, 7, 12, 63};
    std::list<int> list3 = {10, 13, 14, 42};

    MergedListsIterator iter(list1, list2, list3);

    std::cout << "Merged sequence: ";
    while (iter.HasNext())
    {
        std::cout << iter.GetNext() << " ";
    }
    std::cout << std::endl;
}

int main()
{
    TestMergedIterator();
    return 0;
}
