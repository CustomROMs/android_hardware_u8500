void ump_arch_unlock(int r0, int r1, int r2)
{
	//r0 = r1;
	//r1 = r2;
	_hwmem_uku_unmap(r1, r2, r2);
}
