void ump_reference_release(int r0)
{
	int r4 = r0; // ump_mem * mem = (ump_mem*)memh;
	if (r4 == 0)
		return;
		
	int r3 = *(int *) r4;
	if (r3 == -1) // if (r3 == -1)
		return;
		
	r0 = *(int *) (r4 + 12); // r0 = mem->ref_lock
	int r1 = 0; // r1 = _UMP_OSU_LOCKMODE_RW;
	_ump_osu_lock_wait(r0, r1);
	
	int r5 = *(int *) (r4 + 16); // 
	r5 -=1;					 // mem->ref_count -= 1;
	*(int *) (r4 + 16) = r5; //
	
	if (r5 == 0) {
		// branch 150c
		r0 = *(int *) (r4 + 20); // r0 = mem->cookie
		ump_arch_release(r0, r1);
		r0 = *(int *) (r4 + 12); // r0 = mem->ref_lock
		r1 = r5; // r1 = mem->ref_count
		_ump_osu_lock_signal(r0, r1);
		r0 = *(int *) (r4 + 12); // r0 = mem->ref_lock
		_ump_osu_lock_term(r0);
		r0 = r4; // r0 = mem;
	
		_ump_osu_free(r0);
	} else {
		// branch 14fc
		r0 = *(int *) (r4 + 12); // r0 = mem->ref_lock
		r1 = 0; // r1 = _UMP_OSU_LOCKMODE_RW
		_ump_osu_lock_signal(r0, r1);
	}
}
