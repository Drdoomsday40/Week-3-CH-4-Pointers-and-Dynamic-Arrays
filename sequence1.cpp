// FILE: sequence1.cxx
// CLASS IMPLEMENTED: sequence (see sequence1.h for documentation)
// INVARIANT for the sequence ADT:
//   1. The number of items in the sequence is in the member variable used;
//   2. For an empty sequence, we do not care what is stored in any of data; for a
//      non-empty sequence the items in the sequence are stored in sequence order from
//      data[0] through data[used-1], and we don't care what's in the rest of
//      data.
//   3. If there is a current item, the that item is in data[current_index];
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

	void sequence::start()
	{
		current_index = 0;
	}

	void sequence::advance()
		// Library facilities used: assert.h
	{
		assert(is_item());
		current_index++;
	}

	void sequence::insert(const value_type& entry)
		// Library facilities used: assert.h, stdlib.h
	{
		size_t i;

		// Check the precondition
		assert(size() < CAPACITY);

		// If there is no current value_type, then set current_index to the front so that
		// the new entry will be placed at the front of the array.
		if (!is_item())
			current_index = 0;

		// Shift other value_types over, and insert the new entry at current_index
		for (i = used; i > current_index; i--)
			data[i] = data[i - 1];
		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
		// Library facilities used: assert.h, stdlib.h
	{
		size_t i;

		// Check the precondition
		assert(size() < CAPACITY);

		if (!is_item()) // There is no current item, so insert new entry at end
			data[current_index] = entry;
		else // There is a current item, so move items over to make room 
		{
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
		size_t i;

		assert(is_item());

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
		return (current_index < used);
	}

	sequence::value_type sequence::current() const
		// Library facilities used: assert.h
	{
		assert(is_item());
		return data[current_index];
	}

}