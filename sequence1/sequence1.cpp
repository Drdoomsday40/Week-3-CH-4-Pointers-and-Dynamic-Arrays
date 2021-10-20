// FILE: sequence1.cpp
// Written by: Lucien Maurice
// CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)
// INVARIANT for the sequence ADT:
//   1. The number of items in the sequence is in the member variable used;
//   2. For an empty sequence, we do not care what is stored in any of the data; for a
//      sequence with data, the items in the sequence are stored in sequence order from
//      data[0] through data[used-1], and we don't care what's in the rest of
//      data.
//   3. If there is a current item, then that item is in data[current_index];
//      Otherwise, current_index equals used.

// #include "stdafx.h"
#include <assert.h>  // Provides assert
#include <stdlib.h>  // Provides size_t
#include "sequence1.h"

namespace main_savitch_3
{

	sequence::sequence()
	{
		used = 0;
		current_index = 0;
	}

	// Postcondition: The first item on the sequence becomes the current item
	// (but if the sequence is empty, then there is no current item).
	// it starts at index 0, 
	void sequence::start()
	{
		current_index = 0;
	}

	void sequence::advance()
		// Library facilities used: assert.h
		// Precondition: is_item returns true, aka assert that it is an item.
		// Postcondition: If the current item = last item in the
		//     sequence, then there is no longer any current item. Else, the new
		//     current item is the item immediately AFTER the original current item.
		// aka current item = last item, then there is no longer a current item
		// else, current item[used], new current item[used + 1]
	{
		assert(is_item());
		current_index++;
	}

	void sequence::insert(const value_type& entry)
		// Library facilities used: assert.h, stdlib.h
		// copy of entry inserted before current_index
		// Precondition: size( ) < CAPACITY. aka size of value needs to fit in capacity
		// Postcondition: A new copy of entry has been inserted in the sequence
		//     before the current item. If there was no current item, then the new entry 
		//     has been inserted at the front of the sequence. In either case, the newly
		//     inserted item is now the current item of the sequence.
		// new copy of entry inserted before current item, (need to move other items first)
		// if no current item, it is inserted at front and 
		// WILL ALWAYS be current item
	{
		size_t i;

		// Checks the precondition, that is room for new entry
		// maybe create member funct for assert(is_int());	// currently infin loops if char
		assert(size() < CAPACITY);

		// If there is no current value_type, then set current_index to the front so that
		// the new entry will be placed at the front of the array.
		if (!is_item())
			current_index = 0;

		// Shift other value_types over, and insert the new entry at current_index
		// starts from back then iter to current_index
		for (i = used; i > current_index; i--)
			data[i] = data[i - 1];
		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
		// Library facilities used: assert.h, stdlib.h
		// copy of entry inserted after current_index
	{
		// how many items in sequence
		size_t i;

		// Check the precondition, that there is enough space for new entry
		assert(size() < CAPACITY);

		if (!is_item()) // There is no current item, so insert new entry at end
			data[current_index] = entry;
		else // There is a current item, so move items over to make room 
		{
			// starts from back then iter to current_index
			for (i = used; i > current_index + 1; i--)
				data[i] = data[i - 1];
			data[current_index + 1] = entry;
			current_index++;
		}

		used++;
	}

	void sequence::remove_current()
		// Library facilties used: assert.h, stdlib.h
	{
		// how many items in sequence
		size_t i;

		assert(is_item());
		// all data is moved -1 element, starting with the next element from current, thereby 
		//  overwriting the current element data
		for (i = current_index + 1; i < used; i++)
			data[i - 1] = data[i];

		used--;
	}

	size_t sequence::size() const
		// Library facilties used: stdlib.h
	{
		return used;
	}

	bool sequence::is_item() const
		// Library facilities used: stdlib.h
	{
		// checks if the current index placement is less than where the used amount is
		// if true 1, otherwise 0
		return (current_index < used);
	}

	sequence::value_type sequence::current() const
		// Library facilities used: assert.h
	{
		assert(is_item());
		return data[current_index];
	}

}