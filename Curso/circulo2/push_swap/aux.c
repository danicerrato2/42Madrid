int sort_stack(t_stack *stacks[], char *commands)
{
	int areSorted[2];

	are_in_order(stacks, &areSorted);
	while (stacks[0]->top != 0 || !areSorted[0] || !areSorted[1])
	{
		if (!areSorted[0] || !areSorted[1])
		{
			// Solo se indica el movimiento
			if (!areSorted[0])
			{
				/*
				 * Ver más pequeño de A:
				 * 	Si bottom -> RRA
				 * 	Si seg 	-> Si bottom < top -> RA
				 * 		-> Si bottom > top -> SA
				 * 	Si top 	-> Si bottom < prebottom -> RRA, RRA, SA, RA, RA
				 */
			}
			if (!areSorted[1])
			{
				/*
				 * Ver más pequeño (neg) de B:
				 * 	Si bottom -> RRB
				 * 	Si seg 	-> Si bottom < top -> RB
				 * 		-> Si bottom > top -> SB
				 * 	Si top -> PA
			 	 */
			}
			// Se hacen comprobaciones y luego movimientos
			/*
			 * Si RR? o S? o R? -> RRR o SS o RR
			 * Si PA y PB -> PB
			 */
		}
		else
			/*
			 * PA
			 */
	}
}