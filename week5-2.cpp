// Merging Two LinkedList function
LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2)
{
	if (plist1->head->next == NULL) return plist2;
	else if (plist2->head->next == NULL) return plist1;
	else {
		// Move the current pointer to the last position.
		Node* cur = plist1->head->next;
		while (cur->next != NULL)
			cur = cur->next;
		// Link the current pointer to the second list.
		cur->next = plist2->head->next;
		// Remove the dummy node from the second list.
		free(plist2->head);
		return plist1;
	}
}
// Make the list in reverse sequence.
void Reverse(LinkedList* plist)
{
	Node* prev = NULL, * cur = NULL;
	Node* next = plist->head->next;
	// Repeat the next node is NULL.
	while (next != NULL)
	{
		// Set the previous, current, and next nodes.
		prev = cur;
		cur = next;
		next = next->next;
		// Change the link of the current node.
		cur->next = prev;
	}
	// Connect the dummy node to the current node.
	plist->head->next = cur;
}








