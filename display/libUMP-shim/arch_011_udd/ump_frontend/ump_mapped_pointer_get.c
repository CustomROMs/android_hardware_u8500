int ump_mapped_pointer_get(int result, int b, int c)
{
	int r4 = result; 
	if (r4 == 0)
	{
		result = r4;
		return result;
	}
	
	int r3 = *(int *) r4;
	if (r3 == -1)
		goto out;
	
	result = *(int *) (r4 + 4);
	if (result != 0)
		return 0;
	
	result = *(int *) (r4 + 20);
	//int r1 = *(int *) (r4 + 8);
	result = ump_arch_lock(result, *(int *) (r4 + 8));
	if (result == 0)
		*(int *) (r4 + 4) = result;
	else
		return 0;
		
out:
	return 0;
}
