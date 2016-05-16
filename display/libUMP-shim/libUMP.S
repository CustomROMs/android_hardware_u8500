    .    .MP.soe format elf32-littlearm
    .    .    .ssembtion .plt:
    .
.globl puts@plt-0x14
puts@plt-0x14:
    .10d8: 	push	{lr}		; (str lr, [sp, #-4]!)
    .10dc: 	ldr	lr, [pc, #4]	; 10e8 <puts@plt-0x4>
    .10e0: 	add	lr, pc, lr
    .10e4: 	ldr	pc, [lr, #8]!
    .10e8: 	muleq	r0, r0, lr
    .
.globl puts@plt
puts@plt:
    .10ec: 	add	ip, pc, #0, 12
    .10f0: 	add	ip, ip, #12288	; 0x3000
    .10f4: 	ldr	pc, [ip, #3728]!	; 0xe90
    .
.globl printf@plt
printf@plt:
    .10f8: 	add	ip, pc, #0, 12
    .10fc: 	add	ip, ip, #12288	; 0x3000
    .1100: 	ldr	pc, [ip, #3720]!	; 0xe88
    .
.globl putchar@plt
putchar@plt:
    .1104: 	add	ip, pc, #0, 12
    .1108: 	add	ip, ip, #12288	; 0x3000
    .110c: 	ldr	pc, [ip, #3712]!	; 0xe80
    .
.globl abort@plt
abort@plt:
    .1110: 	add	ip, pc, #0, 12
    .1114: 	add	ip, ip, #12288	; 0x3000
    .1118: 	ldr	pc, [ip, #3704]!	; 0xe78
    .
.globl open@plt
open@plt:
    .111c: 	add	ip, pc, #0, 12
    .1120: 	add	ip, ip, #12288	; 0x3000
    .1124: 	ldr	pc, [ip, #3696]!	; 0xe70
    .
.globl close@plt
close@plt:
    .1128: 	add	ip, pc, #0, 12
    .112c: 	add	ip, ip, #12288	; 0x3000
    .1130: 	ldr	pc, [ip, #3688]!	; 0xe68
    .
.globl ioctl@plt
ioctl@plt:
    .1134: 	add	ip, pc, #0, 12
    .1138: 	add	ip, ip, #12288	; 0x3000
    .113c: 	ldr	pc, [ip, #3680]!	; 0xe60
    .
.globl mmap@plt
mmap@plt:
    .1140: 	add	ip, pc, #0, 12
    .1144: 	add	ip, ip, #12288	; 0x3000
    .1148: 	ldr	pc, [ip, #3672]!	; 0xe58
    .
.globl munmap@plt
munmap@plt:
    .114c: 	add	ip, pc, #0, 12
    .1150: 	add	ip, ip, #12288	; 0x3000
    .1154: 	ldr	pc, [ip, #3664]!	; 0xe50
    .
.globl calloc@plt
calloc@plt:
    .1158: 	add	ip, pc, #0, 12
    .115c: 	add	ip, ip, #12288	; 0x3000
    .1160: 	ldr	pc, [ip, #3656]!	; 0xe48
    .
.globl malloc@plt
malloc@plt:
    .1164: 	add	ip, pc, #0, 12
    .1168: 	add	ip, ip, #12288	; 0x3000
    .116c: 	ldr	pc, [ip, #3648]!	; 0xe40
    .
.globl realloc@plt
realloc@plt:
    .1170: 	add	ip, pc, #0, 12
    .1174: 	add	ip, ip, #12288	; 0x3000
    .1178: 	ldr	pc, [ip, #3640]!	; 0xe38
    .
.globl free@plt
free@plt:
    .117c: 	add	ip, pc, #0, 12
    .1180: 	add	ip, ip, #12288	; 0x3000
    .1184: 	ldr	pc, [ip, #3632]!	; 0xe30
    .
.globl memcpy@plt
memcpy@plt:
    .1188: 	add	ip, pc, #0, 12
    .118c: 	add	ip, ip, #12288	; 0x3000
    .1190: 	ldr	pc, [ip, #3624]!	; 0xe28
    .
.globl memset@plt
memset@plt:
    .1194: 	add	ip, pc, #0, 12
    .1198: 	add	ip, ip, #12288	; 0x3000
    .119c: 	ldr	pc, [ip, #3616]!	; 0xe20
    .
.globl memcmp@plt
memcmp@plt:
    .11a0: 	add	ip, pc, #0, 12
    .11a4: 	add	ip, ip, #12288	; 0x3000
    .11a8: 	ldr	pc, [ip, #3608]!	; 0xe18
    .
.globl pthread_mutexattr_init@plt
pthread_mutexattr_init@plt:
    .11ac: 	add	ip, pc, #0, 12
    .11b0: 	add	ip, ip, #12288	; 0x3000
    .11b4: 	ldr	pc, [ip, #3600]!	; 0xe10
    .
.globl pthread_mutexattr_settype@plt
pthread_mutexattr_settype@plt:
    .11b8: 	add	ip, pc, #0, 12
    .11bc: 	add	ip, ip, #12288	; 0x3000
    .11c0: 	ldr	pc, [ip, #3592]!	; 0xe08
    .
.globl pthread_mutex_init@plt
pthread_mutex_init@plt:
    .11c4: 	add	ip, pc, #0, 12
    .11c8: 	add	ip, ip, #12288	; 0x3000
    .11cc: 	ldr	pc, [ip, #3584]!	; 0xe00
    .
.globl pthread_mutexattr_destroy@plt
pthread_mutexattr_destroy@plt:
    .11d0: 	add	ip, pc, #0, 12
    .11d4: 	add	ip, ip, #12288	; 0x3000
    .11d8: 	ldr	pc, [ip, #3576]!	; 0xdf8
    .
.globl pthread_cond_init@plt
pthread_cond_init@plt:
    .11dc: 	add	ip, pc, #0, 12
    .11e0: 	add	ip, ip, #12288	; 0x3000
    .11e4: 	ldr	pc, [ip, #3568]!	; 0xdf0
    .
.globl pthread_mutex_destroy@plt
pthread_mutex_destroy@plt:
    .11e8: 	add	ip, pc, #0, 12
    .11ec: 	add	ip, ip, #12288	; 0x3000
    .11f0: 	ldr	pc, [ip, #3560]!	; 0xde8
    .
.globl pthread_mutex_lock@plt
pthread_mutex_lock@plt:
    .11f4: 	add	ip, pc, #0, 12
    .11f8: 	add	ip, ip, #12288	; 0x3000
    .11fc: 	ldr	pc, [ip, #3552]!	; 0xde0
    .
.globl pthread_mutex_unlock@plt
pthread_mutex_unlock@plt:
    .1200: 	add	ip, pc, #0, 12
    .1204: 	add	ip, ip, #12288	; 0x3000
    .1208: 	ldr	pc, [ip, #3544]!	; 0xdd8
    .
.globl gettimeofday@plt
gettimeofday@plt:
    .120c: 	add	ip, pc, #0, 12
    .1210: 	add	ip, ip, #12288	; 0x3000
    .1214: 	ldr	pc, [ip, #3536]!	; 0xdd0
    .
.globl pthread_cond_timedwait@plt
pthread_cond_timedwait@plt:
    .1218: 	add	ip, pc, #0, 12
    .121c: 	add	ip, ip, #12288	; 0x3000
    .1220: 	ldr	pc, [ip, #3528]!	; 0xdc8
    .
.globl pthread_cond_wait@plt
pthread_cond_wait@plt:
    .1224: 	add	ip, pc, #0, 12
    .1228: 	add	ip, ip, #12288	; 0x3000
    .122c: 	ldr	pc, [ip, #3520]!	; 0xdc0
    .
.globl pthread_mutex_trylock@plt
pthread_mutex_trylock@plt:
    .1230: 	add	ip, pc, #0, 12
    .1234: 	add	ip, ip, #12288	; 0x3000
    .1238: 	ldr	pc, [ip, #3512]!	; 0xdb8
    .
.globl pthread_cond_signal@plt
pthread_cond_signal@plt:
    .123c: 	add	ip, pc, #0, 12
    .1240: 	add	ip, ip, #12288	; 0x3000
    .1244: 	ldr	pc, [ip, #3504]!	; 0xdb0
    .
.globl pthread_cond_destroy@plt
pthread_cond_destroy@plt:
    .1248: 	add	ip, pc, #0, 12
    .124c: 	add	ip, ip, #12288	; 0x3000
    .1250: 	ldr	pc, [ip, #3496]!	; 0xda8
    .
.globl __cxa_finalize@plt
__cxa_finalize@plt:
    .1254: 	add	ip, pc, #0, 12
    .1258: 	add	ip, ip, #12288	; 0x3000
    .125c: 	ldr	pc, [ip, #3488]!	; 0xda0
    .    .ssembtion .text:
    .
.globl ump_open
ump_open:
    .1260: 	b	1814 <ump_arch_open>
    .
.globl ump_close
ump_close:
    .1264: 	b	1964 <ump_arch_close>
    .
.globl ump_secure_id_get
ump_secure_id_get:
    .1268: 	cmp	r0, #0
    .126c: 	ldrne	r0, [r0]
    .1270: 	mvneq	r0, #0
    .1274: 	bx	lr
    .
.globl ump_handle_create_from_secure_id
ump_handle_create_from_secure_id:
    .1278: 	cmn	r0, #1
    .127c: 	push	{r4, r5, r6, r7, lr}
    .1280: 	mov	r6, r0
    .1284: 	sub	sp, sp, #12
    .1288: 	moveq	r4, #0
    .128c: 	beq	130c <ump_handle_create_from_secure_id+0x94>
    .1290: 	add	r1, sp, #4
    .1294: 	bl	1b74 <ump_arch_import>
    .1298: 	ldr	r1, [sp, #4]
    .129c: 	cmp	r1, #0
    .12a0: 	moveq	r4, r1
    .12a4: 	mov	r5, r0
    .12a8: 	beq	130c <ump_handle_create_from_secure_id+0x94>
    .12ac: 	bl	1c58 <ump_arch_lock>
    .12b0: 	subs	r7, r0, #0
    .12b4: 	moveq	r4, r7
    .12b8: 	beq	130c <ump_handle_create_from_secure_id+0x94>
    .12bc: 	mov	r0, #1
    .12c0: 	mov	r1, #28
    .12c4: 	bl	1eb0 <_ump_osu_calloc>
    .12c8: 	subs	r4, r0, #0
    .12cc: 	beq	1318 <ump_handle_create_from_secure_id+0xa0>
    .12d0: 	ldr	r3, [sp, #4]
    .12d4: 	mov	r1, #0
    .12d8: 	str	r6, [r4]
    .12dc: 	add	r0, r4, #12
    .12e0: 	str	r7, [r4, #4]
    .12e4: 	mov	r2, r1
    .12e8: 	str	r3, [r4, #8]
    .12ec: 	mov	r3, r1
    .12f0: 	str	r5, [r4, #20]
    .12f4: 	bl	207c <_ump_osu_lock_auto_init>
    .12f8: 	ldr	r3, [r4, #12]
    .12fc: 	cmp	r3, #0
    .1300: 	movne	r3, #1
    .1304: 	strne	r3, [r4, #16]
    .1308: 	beq	1334 <ump_handle_create_from_secure_id+0xbc>
    .130c: 	mov	r0, r4
    .1310: 	add	sp, sp, #12
    .1314: 	pop	{r4, r5, r6, r7, pc}
    .1318: 	mov	r0, r5
    .131c: 	mov	r1, r7
    .1320: 	ldr	r2, [sp, #4]
    .1324: 	bl	1c80 <ump_arch_unlock>
    .1328: 	mov	r0, r5
    .132c: 	bl	1bdc <ump_arch_release>
    .1330: 	b	130c <ump_handle_create_from_secure_id+0x94>
    .1334: 	mov	r4, r3
    .1338: 	b	130c <ump_handle_create_from_secure_id+0x94>
    .
.globl ump_size_get
ump_size_get:
    .133c: 	cmp	r0, #0
    .1340: 	bxeq	lr
    .1344: 	ldr	r3, [r0]
    .1348: 	cmn	r3, #1
    .134c: 	ldrne	r0, [r0, #8]
    .1350: 	moveq	r0, #0
    .1354: 	bx	lr
    .
.globl ump_read
ump_read:
    .1358: 	cmp	r1, #0
    .135c: 	bxeq	lr
    .1360: 	ldr	ip, [r1]
    .1364: 	cmn	ip, #1
    .1368: 	bxeq	lr
    .136c: 	ldr	r1, [r1, #4]
    .1370: 	cmp	r1, #0
    .1374: 	bxeq	lr
    .1378: 	add	r1, r1, r2
    .137c: 	mov	r2, r3
    .1380: 	b	1ec0 <_ump_osu_memcpy>
    .
.globl ump_write
ump_write:
    .1384: 	cmp	r0, #0
    .1388: 	bxeq	lr
    .138c: 	ldr	ip, [r0]
    .1390: 	cmn	ip, #1
    .1394: 	bxeq	lr
    .1398: 	ldr	r0, [r0, #4]
    .139c: 	cmp	r0, #0
    .13a0: 	bxeq	lr
    .13a4: 	add	r0, r0, r1
    .13a8: 	mov	r1, r2
    .13ac: 	mov	r2, r3
    .13b0: 	b	1ec0 <_ump_osu_memcpy>
    .
.globl ump_mapped_pointer_get
ump_mapped_pointer_get:
    .13b4: 	push	{r4, lr}
    .13b8: 	subs	r4, r0, #0
    .13bc: 	moveq	r0, r4
    .13c0: 	popeq	{r4, pc}
    .13c4: 	ldr	r3, [r4]
    .13c8: 	cmn	r3, #1
    .13cc: 	beq	143c <ump_mapped_pointer_get+0x88>
    .13d0: 	ldr	r0, [r4, #4]
    .13d4: 	cmp	r0, #0
    .13d8: 	popne	{r4, pc}
    .13dc: 	ldr	r0, [r4, #20]
    .13e0: 	ldr	r1, [r4, #8]
    .13e4: 	bl	1c58 <ump_arch_lock>
    .13e8: 	cmp	r0, #0
    .13ec: 	str	r0, [r4, #4]
    .13f0: 	popne	{r4, pc}
    .13f4: 	ldr	ip, [pc, #72]	; 1444 <ump_mapped_pointer_get+0x90>
    .13f8: 	ldr	r4, [pc, #72]	; 1448 <ump_mapped_pointer_get+0x94>
    .13fc: 	add	r0, pc, ip
    .1400: 	bl	10ec <puts@plt>
    .1404: 	ldr	r2, [pc, #64]	; 144c <ump_mapped_pointer_get+0x98>
    .1408: 	add	r0, pc, r2
    .140c: 	bl	10f8 <printf@plt>
    .1410: 	ldr	r1, [pc, #56]	; 1450 <ump_mapped_pointer_get+0x9c>
    .1414: 	mov	r2, #146	; 0x92
    .1418: 	add	r0, pc, r4
    .141c: 	add	r1, pc, r1
    .1420: 	bl	10f8 <printf@plt>
    .1424: 	ldr	r0, [pc, #40]	; 1454 <ump_mapped_pointer_get+0xa0>
    .1428: 	add	r0, pc, r0
    .142c: 	bl	10f8 <printf@plt>
    .1430: 	mov	r0, #10
    .1434: 	bl	1104 <putchar@plt>
    .1438: 	bl	1110 <abort@plt>
    .143c: 	mov	r0, #0
    .1440: 	pop	{r4, pc}
    .1444: 	andeq	r1, r0, ip, lsr #28
    .1448: 	andeq	r1, r0, r8, ror #28
    .144c: 	andeq	r1, r0, r8, ror #28
    .1450: 	andeq	r1, r0, r8, lsl pc
    .1454: 	andeq	r1, r0, r4, ror #29
    .
.globl ump_mapped_pointer_release
ump_mapped_pointer_release:
    .1458: 	ldr	r1, [r0, #4]
    .145c: 	push	{r4, lr}
    .1460: 	cmp	r1, #0
    .1464: 	mov	r4, r0
    .1468: 	beq	1478 <ump_mapped_pointer_release+0x20>
    .146c: 	ldr	r0, [r0, #20]
    .1470: 	ldr	r2, [r4, #8]
    .1474: 	bl	1c80 <ump_arch_unlock>
    .1478: 	mov	r3, #0
    .147c: 	str	r3, [r4, #4]
    .1480: 	pop	{r4, pc}
    .
.globl ump_reference_add
ump_reference_add:
    .1484: 	push	{r4, lr}
    .1488: 	subs	r4, r0, #0
    .148c: 	popeq	{r4, pc}
    .1490: 	ldr	r3, [r4]
    .1494: 	cmn	r3, #1
    .1498: 	popeq	{r4, pc}
    .149c: 	mov	r1, #0
    .14a0: 	ldr	r0, [r4, #12]
    .14a4: 	bl	25ac <_ump_osu_lock_wait>
    .14a8: 	ldr	ip, [r4, #16]
    .14ac: 	ldr	r0, [r4, #12]
    .14b0: 	mov	r1, #0
    .14b4: 	add	r2, ip, #1
    .14b8: 	str	r2, [r4, #16]
    .14bc: 	pop	{r4, lr}
    .14c0: 	b	2b40 <_ump_osu_lock_signal>
    .
.globl ump_reference_release
ump_reference_release:
    .14c4: 	push	{r3, r4, r5, lr}
    .14c8: 	subs	r4, r0, #0
    .14cc: 	popeq	{r3, r4, r5, pc}
    .14d0: 	ldr	r3, [r4]
    .14d4: 	cmn	r3, #1
    .14d8: 	popeq	{r3, r4, r5, pc}
    .14dc: 	ldr	r0, [r4, #12]
    .14e0: 	mov	r1, #0
    .14e4: 	bl	25ac <_ump_osu_lock_wait>
    .14e8: 	ldr	r5, [r4, #16]
    .14ec: 	sub	r5, r5, #1
    .14f0: 	str	r5, [r4, #16]
    .14f4: 	cmp	r5, #0
    .14f8: 	beq	150c <ump_reference_release+0x48>
    .14fc: 	ldr	r0, [r4, #12]
    .1500: 	mov	r1, #0
    .1504: 	pop	{r3, r4, r5, lr}
    .1508: 	b	2b40 <_ump_osu_lock_signal>
    .150c: 	ldr	r0, [r4, #20]
    .1510: 	bl	1bdc <ump_arch_release>
    .1514: 	ldr	r0, [r4, #12]
    .1518: 	mov	r1, r5
    .151c: 	bl	2b40 <_ump_osu_lock_signal>
    .1520: 	ldr	r0, [r4, #12]
    .1524: 	bl	2e80 <_ump_osu_lock_term>
    .1528: 	mov	r0, r4
    .152c: 	pop	{r3, r4, r5, lr}
    .1530: 	b	1ebc <_ump_osu_free>
    .
.globl ump_ref_drv_allocate
ump_ref_drv_allocate:
    .1534: 	push	{r4, r5, lr}
    .1538: 	sub	sp, sp, #12
    .153c: 	add	r3, sp, #8
    .1540: 	str	r0, [r3, #-4]!
    .1544: 	mov	r0, r3
    .1548: 	bl	1b14 <ump_arch_allocate>
    .154c: 	subs	r5, r0, #0
    .1550: 	ble	15bc <ump_ref_drv_allocate+0x88>
    .1554: 	mov	r0, #1
    .1558: 	mov	r1, #28
    .155c: 	bl	1eb0 <_ump_osu_calloc>
    .1560: 	subs	r4, r0, #0
    .1564: 	mov	r0, r5
    .1568: 	beq	15c4 <ump_ref_drv_allocate+0x90>
    .156c: 	bl	1bc8 <ump_arch_export>
    .1570: 	ldr	r2, [sp, #4]
    .1574: 	mov	ip, #0
    .1578: 	str	r5, [r4, #20]
    .157c: 	mov	r1, ip
    .1580: 	str	ip, [r4, #4]
    .1584: 	str	r2, [r4, #8]
    .1588: 	mov	r3, ip
    .158c: 	mov	r2, ip
    .1590: 	str	r0, [r4]
    .1594: 	add	r0, r4, #12
    .1598: 	bl	207c <_ump_osu_lock_auto_init>
    .159c: 	ldr	r0, [r4, #12]
    .15a0: 	cmp	r0, #0
    .15a4: 	movne	r0, #1
    .15a8: 	strne	r0, [r4, #16]
    .15ac: 	beq	15cc <ump_ref_drv_allocate+0x98>
    .15b0: 	mov	r0, r4
    .15b4: 	add	sp, sp, #12
    .15b8: 	pop	{r4, r5, pc}
    .15bc: 	mov	r4, #0
    .15c0: 	b	15b0 <ump_ref_drv_allocate+0x7c>
    .15c4: 	bl	1bdc <ump_arch_release>
    .15c8: 	b	15b0 <ump_ref_drv_allocate+0x7c>
    .15cc: 	ldr	lr, [pc, #64]	; 1614 <ump_ref_drv_allocate+0xe0>
    .15d0: 	ldr	r5, [pc, #64]	; 1618 <ump_ref_drv_allocate+0xe4>
    .15d4: 	add	r0, pc, lr
    .15d8: 	ldr	r4, [pc, #60]	; 161c <ump_ref_drv_allocate+0xe8>
    .15dc: 	bl	10ec <puts@plt>
    .15e0: 	ldr	r3, [pc, #56]	; 1620 <ump_ref_drv_allocate+0xec>
    .15e4: 	add	r0, pc, r3
    .15e8: 	bl	10f8 <printf@plt>
    .15ec: 	mov	r2, #48	; 0x30
    .15f0: 	add	r1, pc, r4
    .15f4: 	add	r0, pc, r5
    .15f8: 	bl	10f8 <printf@plt>
    .15fc: 	ldr	r1, [pc, #32]	; 1624 <ump_ref_drv_allocate+0xf0>
    .1600: 	add	r0, pc, r1
    .1604: 	bl	10ec <puts@plt>
    .1608: 	mov	r0, #10
    .160c: 	bl	1104 <putchar@plt>
    .1610: 	bl	1110 <abort@plt>
    .1614: 	andeq	r1, r0, r4, lsr #27
    .1618: 	ldrdeq	r1, [r0], -ip
    .161c: 	andeq	r1, r0, ip, asr sp
    .1620: 	ldrdeq	r1, [r0], -ip
    .1624: 	andeq	r1, r0, ip, asr lr
    .
.globl ump_cpu_msync_now
ump_cpu_msync_now:
    .1628: 	push	{r4, r5, r6, lr}
    .162c: 	subs	r4, r0, #0
    .1630: 	sub	sp, sp, #8
    .1634: 	mov	r5, r1
    .1638: 	mov	ip, r3
    .163c: 	beq	1734 <ump_cpu_msync_now+0x10c>
    .1640: 	ldr	r6, [r4, #16]
    .1644: 	cmp	r6, #0
    .1648: 	ble	16ec <ump_cpu_msync_now+0xc4>
    .164c: 	cmp	r3, #0
    .1650: 	blt	16a4 <ump_cpu_msync_now+0x7c>
    .1654: 	ldr	lr, [r4, #8]
    .1658: 	cmp	r3, lr
    .165c: 	bhi	16a4 <ump_cpu_msync_now+0x7c>
    .1660: 	ldr	r1, [r4, #4]
    .1664: 	cmp	r1, #0
    .1668: 	beq	177c <ump_cpu_msync_now+0x154>
    .166c: 	ldr	r6, [r4, #20]
    .1670: 	cmp	ip, #0
    .1674: 	ldr	r0, [r4]
    .1678: 	mov	r3, r2
    .167c: 	moveq	ip, lr
    .1680: 	str	r5, [sp, #4]
    .1684: 	mov	r2, r6
    .1688: 	cmp	lr, ip
    .168c: 	strle	lr, [sp]
    .1690: 	strgt	ip, [sp]
    .1694: 	bl	1c90 <ump_arch_msync>
    .1698: 	str	r0, [r4, #24]
    .169c: 	add	sp, sp, #8
    .16a0: 	pop	{r4, r5, r6, pc}
    .16a4: 	ldr	r5, [pc, #280]	; 17c4 <ump_cpu_msync_now+0x19c>
    .16a8: 	ldr	r6, [pc, #280]	; 17c8 <ump_cpu_msync_now+0x1a0>
    .16ac: 	add	r0, pc, r5
    .16b0: 	ldr	r4, [pc, #276]	; 17cc <ump_cpu_msync_now+0x1a4>
    .16b4: 	bl	10ec <puts@plt>
    .16b8: 	ldr	r2, [pc, #272]	; 17d0 <ump_cpu_msync_now+0x1a8>
    .16bc: 	add	r0, pc, r2
    .16c0: 	bl	10f8 <printf@plt>
    .16c4: 	mov	r2, #73	; 0x49
    .16c8: 	add	r1, pc, r4
    .16cc: 	add	r0, pc, r6
    .16d0: 	bl	10f8 <printf@plt>
    .16d4: 	ldr	r3, [pc, #248]	; 17d4 <ump_cpu_msync_now+0x1ac>
    .16d8: 	add	r0, pc, r3
    .16dc: 	bl	10f8 <printf@plt>
    .16e0: 	mov	r0, #10
    .16e4: 	bl	1104 <putchar@plt>
    .16e8: 	bl	1110 <abort@plt>
    .16ec: 	ldr	lr, [pc, #228]	; 17d8 <ump_cpu_msync_now+0x1b0>
    .16f0: 	ldr	r5, [pc, #228]	; 17dc <ump_cpu_msync_now+0x1b4>
    .16f4: 	add	r0, pc, lr
    .16f8: 	bl	10ec <puts@plt>
    .16fc: 	ldr	r1, [pc, #220]	; 17e0 <ump_cpu_msync_now+0x1b8>
    .1700: 	add	r0, pc, r1
    .1704: 	bl	10f8 <printf@plt>
    .1708: 	ldr	ip, [pc, #212]	; 17e4 <ump_cpu_msync_now+0x1bc>
    .170c: 	ldr	r0, [pc, #212]	; 17e8 <ump_cpu_msync_now+0x1c0>
    .1710: 	mov	r2, #72	; 0x48
    .1714: 	add	r1, pc, ip
    .1718: 	add	r0, pc, r0
    .171c: 	bl	10f8 <printf@plt>
    .1720: 	add	r0, pc, r5
    .1724: 	bl	10f8 <printf@plt>
    .1728: 	mov	r0, #10
    .172c: 	bl	1104 <putchar@plt>
    .1730: 	bl	1110 <abort@plt>
    .1734: 	ldr	r4, [pc, #176]	; 17ec <ump_cpu_msync_now+0x1c4>
    .1738: 	add	r0, pc, r4
    .173c: 	bl	10ec <puts@plt>
    .1740: 	ldr	r2, [pc, #168]	; 17f0 <ump_cpu_msync_now+0x1c8>
    .1744: 	add	r0, pc, r2
    .1748: 	bl	10f8 <printf@plt>
    .174c: 	ldr	r3, [pc, #160]	; 17f4 <ump_cpu_msync_now+0x1cc>
    .1750: 	ldr	r1, [pc, #160]	; 17f8 <ump_cpu_msync_now+0x1d0>
    .1754: 	mov	r2, #70	; 0x46
    .1758: 	add	r0, pc, r3
    .175c: 	add	r1, pc, r1
    .1760: 	bl	10f8 <printf@plt>
    .1764: 	ldr	r0, [pc, #144]	; 17fc <ump_cpu_msync_now+0x1d4>
    .1768: 	add	r0, pc, r0
    .176c: 	bl	10f8 <printf@plt>
    .1770: 	mov	r0, #10
    .1774: 	bl	1104 <putchar@plt>
    .1778: 	bl	1110 <abort@plt>
    .177c: 	ldr	lr, [pc, #124]	; 1800 <ump_cpu_msync_now+0x1d8>
    .1780: 	add	r0, pc, lr
    .1784: 	bl	10ec <puts@plt>
    .1788: 	ldr	r3, [pc, #116]	; 1804 <ump_cpu_msync_now+0x1dc>
    .178c: 	add	r0, pc, r3
    .1790: 	bl	10f8 <printf@plt>
    .1794: 	ldr	r0, [pc, #108]	; 1808 <ump_cpu_msync_now+0x1e0>
    .1798: 	ldr	r1, [pc, #108]	; 180c <ump_cpu_msync_now+0x1e4>
    .179c: 	mov	r2, #74	; 0x4a
    .17a0: 	add	r0, pc, r0
    .17a4: 	add	r1, pc, r1
    .17a8: 	bl	10f8 <printf@plt>
    .17ac: 	ldr	ip, [pc, #92]	; 1810 <ump_cpu_msync_now+0x1e8>
    .17b0: 	add	r0, pc, ip
    .17b4: 	bl	10f8 <printf@plt>
    .17b8: 	mov	r0, #10
    .17bc: 	bl	1104 <putchar@plt>
    .17c0: 	bl	1110 <abort@plt>
    .17c4: 	andeq	r1, r0, ip, asr #25
    .17c8: 	andeq	r1, r0, r4, lsl #26
    .17cc: 	muleq	r0, ip, ip
    .17d0: 	andeq	r1, r0, r4, lsl #26
    .17d4: 	andeq	r1, r0, ip, asr #27
    .17d8: 	andeq	r1, r0, r4, lsl #25
    .17dc: 	andeq	r1, r0, ip, ror #26
    .17e0: 	andeq	r1, r0, r0, asr #25
    .17e4: 	andeq	r1, r0, r0, asr ip
    .17e8: 			; <UNDEFINED> instruction: 0x00001cb8
    .17ec: 	andeq	r1, r0, r0, asr #24
    .17f0: 	andeq	r1, r0, ip, ror ip
    .17f4: 	andeq	r1, r0, r8, ror ip
    .17f8: 	andeq	r1, r0, r8, lsl #24
    .17fc: 	andeq	r1, r0, r0, lsl sp
    .1800: 	strdeq	r1, [r0], -r8
    .1804: 	andeq	r1, r0, r4, lsr ip
    .1808: 	andeq	r1, r0, r0, lsr ip
    .180c: 	andeq	r1, r0, r0, asr #23
    .1810: 	andeq	r1, r0, ip, lsl sp
    .
.globl ump_arch_open
ump_arch_open:
    .1814: 	ldr	r0, [pc, #280]	; 1934 <ump_arch_open+0x120>
    .1818: 	mov	r1, #0
    .181c: 	push	{r3, r4, r5, lr}
    .1820: 	add	r4, pc, r0
    .1824: 	mov	r2, r1
    .1828: 	mov	r3, r1
    .182c: 	mov	r0, r4
    .1830: 	bl	207c <_ump_osu_lock_auto_init>
    .1834: 	ldr	r0, [r4]
    .1838: 	cmp	r0, #0
    .183c: 	beq	18ac <ump_arch_open+0x98>
    .1840: 	mov	r1, #0
    .1844: 	bl	25ac <_ump_osu_lock_wait>
    .1848: 	subs	r4, r0, #0
    .184c: 	bne	1894 <ump_arch_open+0x80>
    .1850: 	ldr	r3, [pc, #224]	; 1938 <ump_arch_open+0x124>
    .1854: 	add	r3, pc, r3
    .1858: 	ldr	r5, [r3]
    .185c: 	cmp	r5, #0
    .1860: 	blt	18ec <ump_arch_open+0xd8>
    .1864: 	ldr	r5, [r3]
    .1868: 	add	r2, r5, #1
    .186c: 	str	r2, [r3]
    .1870: 	ldr	r5, [r3]
    .1874: 	cmp	r5, #1
    .1878: 	beq	18c4 <ump_arch_open+0xb0>
    .187c: 	ldr	r0, [pc, #184]	; 193c <ump_arch_open+0x128>
    .1880: 	mov	r1, #0
    .1884: 	ldr	r0, [pc, r0]
    .1888: 	bl	2b40 <_ump_osu_lock_signal>
    .188c: 	mov	r0, r4
    .1890: 	pop	{r3, r4, r5, pc}
    .1894: 	ldr	r2, [pc, #164]	; 1940 <ump_arch_open+0x12c>
    .1898: 	mov	r4, #1
    .189c: 	add	r0, pc, r2
    .18a0: 	bl	10ec <puts@plt>
    .18a4: 	mov	r0, r4
    .18a8: 	pop	{r3, r4, r5, pc}
    .18ac: 	ldr	r1, [pc, #144]	; 1944 <ump_arch_open+0x130>
    .18b0: 	mov	r4, #1
    .18b4: 	add	r0, pc, r1
    .18b8: 	bl	10ec <puts@plt>
    .18bc: 	mov	r0, r4
    .18c0: 	pop	{r3, r4, r5, pc}
    .18c4: 	ldr	r3, [pc, #124]	; 1948 <ump_arch_open+0x134>
    .18c8: 	add	r0, pc, r3
    .18cc: 	bl	1d20 <_hwmem_uku_open>
    .18d0: 	subs	r4, r0, #0
    .18d4: 	beq	187c <ump_arch_open+0x68>
    .18d8: 	ldr	ip, [pc, #108]	; 194c <ump_arch_open+0x138>
    .18dc: 	mov	r4, r5
    .18e0: 	add	r0, pc, ip
    .18e4: 	bl	10ec <puts@plt>
    .18e8: 	b	187c <ump_arch_open+0x68>
    .18ec: 	ldr	lr, [pc, #92]	; 1950 <ump_arch_open+0x13c>
    .18f0: 	ldr	r4, [pc, #92]	; 1954 <ump_arch_open+0x140>
    .18f4: 	add	r0, pc, lr
    .18f8: 	bl	10ec <puts@plt>
    .18fc: 	ldr	r1, [pc, #84]	; 1958 <ump_arch_open+0x144>
    .1900: 	add	r0, pc, r1
    .1904: 	bl	10f8 <printf@plt>
    .1908: 	ldr	r0, [pc, #76]	; 195c <ump_arch_open+0x148>
    .190c: 	mov	r2, #53	; 0x35
    .1910: 	add	r1, pc, r4
    .1914: 	add	r0, pc, r0
    .1918: 	bl	10f8 <printf@plt>
    .191c: 	ldr	ip, [pc, #60]	; 1960 <ump_arch_open+0x14c>
    .1920: 	add	r0, pc, ip
    .1924: 	bl	10f8 <printf@plt>
    .1928: 	mov	r0, #10
    .192c: 	bl	1104 <putchar@plt>
    .1930: 	bl	1110 <abort@plt>
    .1934: 	andeq	r3, r0, r8, lsr #16
    .1938: 	strdeq	r3, [r0], -ip
    .193c: 	andeq	r3, r0, r4, asr #15
    .1940: 	muleq	r0, r8, ip
    .1944: 	andeq	r1, r0, r4, asr ip
    .1948: 	andeq	r3, r0, r4, lsl #15
    .194c: 	muleq	r0, r8, sp
    .1950: 	andeq	r1, r0, ip, ror #24
    .1954: 	muleq	r0, r4, lr
    .1958: 	andeq	r1, r0, r8, lsr #25
    .195c: 	andeq	r1, r0, r4, lsr #25
    .1960: 	andeq	r1, r0, r0, lsr #26
    .
.globl ump_arch_close
ump_arch_close:
    .1964: 	push	{r4, r5, r6, lr}
    .1968: 	mov	r1, #0
    .196c: 	ldr	r4, [pc, #352]	; 1ad4 <ump_arch_close+0x170>
    .1970: 	mov	r2, r1
    .1974: 	mov	r3, r1
    .1978: 	add	r4, pc, r4
    .197c: 	mov	r0, r4
    .1980: 	bl	207c <_ump_osu_lock_auto_init>
    .1984: 	ldr	r0, [r4]
    .1988: 	cmp	r0, #0
    .198c: 	beq	1a34 <ump_arch_close+0xd0>
    .1990: 	mov	r1, #0
    .1994: 	bl	25ac <_ump_osu_lock_wait>
    .1998: 	cmp	r0, #0
    .199c: 	bne	1a24 <ump_arch_close+0xc0>
    .19a0: 	ldr	r3, [pc, #304]	; 1ad8 <ump_arch_close+0x174>
    .19a4: 	add	r3, pc, r3
    .19a8: 	ldr	r2, [r3]
    .19ac: 	cmp	r2, #0
    .19b0: 	ble	1a44 <ump_arch_close+0xe0>
    .19b4: 	ldr	r0, [r3]
    .19b8: 	cmp	r0, #0
    .19bc: 	ble	19d8 <ump_arch_close+0x74>
    .19c0: 	ldr	ip, [r3]
    .19c4: 	sub	r2, ip, #1
    .19c8: 	str	r2, [r3]
    .19cc: 	ldr	r1, [r3]
    .19d0: 	cmp	r1, #0
    .19d4: 	beq	19ec <ump_arch_close+0x88>
    .19d8: 	ldr	r2, [pc, #252]	; 1adc <ump_arch_close+0x178>
    .19dc: 	mov	r1, #0
    .19e0: 	ldr	r0, [pc, r2]
    .19e4: 	pop	{r4, r5, r6, lr}
    .19e8: 	b	2b40 <_ump_osu_lock_signal>
    .19ec: 	ldr	r3, [pc, #236]	; 1ae0 <ump_arch_close+0x17c>
    .19f0: 	add	r5, pc, r3
    .19f4: 	mov	r0, r5
    .19f8: 	bl	1d58 <_hwmem_uku_close>
    .19fc: 	subs	r6, r0, #0
    .1a00: 	bne	1a8c <ump_arch_close+0x128>
    .1a04: 	ldr	r0, [r4]
    .1a08: 	mov	r1, r6
    .1a0c: 	str	r6, [r5]
    .1a10: 	bl	2b40 <_ump_osu_lock_signal>
    .1a14: 	ldr	r0, [r4]
    .1a18: 	bl	2e80 <_ump_osu_lock_term>
    .1a1c: 	str	r6, [r4]
    .1a20: 	pop	{r4, r5, r6, pc}
    .1a24: 	ldr	r1, [pc, #184]	; 1ae4 <ump_arch_close+0x180>
    .1a28: 	add	r0, pc, r1
    .1a2c: 	pop	{r4, r5, r6, lr}
    .1a30: 	b	10ec <puts@plt>
    .1a34: 	ldr	r0, [pc, #172]	; 1ae8 <ump_arch_close+0x184>
    .1a38: 	add	r0, pc, r0
    .1a3c: 	pop	{r4, r5, r6, lr}
    .1a40: 	b	10ec <puts@plt>
    .1a44: 	ldr	lr, [pc, #160]	; 1aec <ump_arch_close+0x188>
    .1a48: 	ldr	r4, [pc, #160]	; 1af0 <ump_arch_close+0x18c>
    .1a4c: 	add	r0, pc, lr
    .1a50: 	ldr	r6, [pc, #156]	; 1af4 <ump_arch_close+0x190>
    .1a54: 	bl	10ec <puts@plt>
    .1a58: 	add	r0, pc, r4
    .1a5c: 	bl	10f8 <printf@plt>
    .1a60: 	ldr	ip, [pc, #144]	; 1af8 <ump_arch_close+0x194>
    .1a64: 	ldr	r5, [pc, #144]	; 1afc <ump_arch_close+0x198>
    .1a68: 	mov	r2, #93	; 0x5d
    .1a6c: 	add	r0, pc, ip
    .1a70: 	add	r1, pc, r6
    .1a74: 	bl	10f8 <printf@plt>
    .1a78: 	add	r0, pc, r5
    .1a7c: 	bl	10f8 <printf@plt>
    .1a80: 	mov	r0, #10
    .1a84: 	bl	1104 <putchar@plt>
    .1a88: 	bl	1110 <abort@plt>
    .1a8c: 	ldr	lr, [pc, #108]	; 1b00 <ump_arch_close+0x19c>
    .1a90: 	ldr	r4, [pc, #108]	; 1b04 <ump_arch_close+0x1a0>
    .1a94: 	add	r0, pc, lr
    .1a98: 	ldr	r6, [pc, #104]	; 1b08 <ump_arch_close+0x1a4>
    .1a9c: 	bl	10ec <puts@plt>
    .1aa0: 	ldr	r0, [pc, #100]	; 1b0c <ump_arch_close+0x1a8>
    .1aa4: 	ldr	r5, [pc, #100]	; 1b10 <ump_arch_close+0x1ac>
    .1aa8: 	add	r0, pc, r0
    .1aac: 	bl	10f8 <printf@plt>
    .1ab0: 	mov	r2, #100	; 0x64
    .1ab4: 	add	r1, pc, r6
    .1ab8: 	add	r0, pc, r4
    .1abc: 	bl	10f8 <printf@plt>
    .1ac0: 	add	r0, pc, r5
    .1ac4: 	bl	10f8 <printf@plt>
    .1ac8: 	mov	r0, #10
    .1acc: 	bl	1104 <putchar@plt>
    .1ad0: 	bl	1110 <abort@plt>
    .1ad4: 	ldrdeq	r3, [r0], -r0
    .1ad8: 	andeq	r3, r0, ip, lsr #13
    .1adc: 	andeq	r3, r0, r8, ror #12
    .1ae0: 	andeq	r3, r0, ip, asr r6
    .1ae4: 			; <UNDEFINED> instruction: 0x00001cb4
    .1ae8: 	andeq	r1, r0, r8, ror ip
    .1aec: 	andeq	r1, r0, r4, lsl fp
    .1af0: 	andeq	r1, r0, r0, asr fp
    .1af4: 	andeq	r1, r0, r4, lsr #26
    .1af8: 	andeq	r1, r0, ip, asr #22
    .1afc: 	muleq	r0, r0, ip
    .1b00: 	andeq	r1, r0, ip, asr #21
    .1b04: 	andeq	r1, r0, r0, lsl #22
    .1b08: 	andeq	r1, r0, r0, ror #25
    .1b0c: 	andeq	r1, r0, r0, lsl #22
    .1b10: 	andeq	r1, r0, r0, lsl #25
    .
.globl ump_arch_allocate
ump_arch_allocate:
    .1b14: 	push	{r4, lr}
    .1b18: 	subs	r4, r0, #0
    .1b1c: 	sub	sp, sp, #16
    .1b20: 	mov	r3, r1
    .1b24: 	mvneq	r0, #0
    .1b28: 	beq	1b68 <ump_arch_allocate+0x54>
    .1b2c: 	ldr	r2, [r4]
    .1b30: 	sub	r3, r3, #1
    .1b34: 	ldr	r0, [pc, #52]	; 1b70 <ump_arch_allocate+0x5c>
    .1b38: 	rsbs	ip, r3, #0
    .1b3c: 	mov	r1, sp
    .1b40: 	adc	lr, ip, r3
    .1b44: 	ldr	r0, [pc, r0]
    .1b48: 	str	r2, [sp]
    .1b4c: 	mov	ip, #7
    .1b50: 	mov	r2, #10
    .1b54: 	str	lr, [sp, #12]
    .1b58: 	stmib	sp, {r2, ip}
    .1b5c: 	bl	1d8c <_hwmem_uku_allocate>
    .1b60: 	ldr	r3, [sp]
    .1b64: 	str	r3, [r4]
    .1b68: 	add	sp, sp, #16
    .1b6c: 	pop	{r4, pc}
    .1b70: 	andeq	r3, r0, r8, lsl #10
    .
.globl ump_arch_import
ump_arch_import:
    .1b74: 	push	{r4, r5, r6, lr}
    .1b78: 	mov	r6, r1
    .1b7c: 	ldr	r4, [pc, #64]	; 1bc4 <ump_arch_import+0x50>
    .1b80: 	sub	sp, sp, #16
    .1b84: 	mov	r1, r0
    .1b88: 	add	r4, pc, r4
    .1b8c: 	ldr	r0, [r4]
    .1b90: 	bl	1db8 <_hwmem_uku_import>
    .1b94: 	mov	r1, sp
    .1b98: 	mov	r2, #0
    .1b9c: 	str	r2, [sp, #4]
    .1ba0: 	mov	r5, r0
    .1ba4: 	ldr	r0, [r4]
    .1ba8: 	str	r5, [sp]
    .1bac: 	bl	1e98 <_hwmem_uku_get_info>
    .1bb0: 	ldr	r3, [sp, #4]
    .1bb4: 	mov	r0, r5
    .1bb8: 	str	r3, [r6]
    .1bbc: 	add	sp, sp, #16
    .1bc0: 	pop	{r4, r5, r6, pc}
    .1bc4: 	andeq	r3, r0, r4, asr #9
    .
.globl ump_arch_export
ump_arch_export:
    .1bc8: 	mov	r1, r0
    .1bcc: 	ldr	r0, [pc, #4]	; 1bd8 <ump_arch_export+0x10>
    .1bd0: 	ldr	r0, [pc, r0]
    .1bd4: 	b	1dcc <_hwmem_uku_export>
    .1bd8: 	andeq	r3, r0, ip, ror r4
    .
.globl ump_arch_release
ump_arch_release:
    .1bdc: 	mov	r1, r0
    .1be0: 	ldr	r0, [pc, #88]	; 1c40 <ump_arch_release+0x64>
    .1be4: 	push	{r3, lr}
    .1be8: 	ldr	r0, [pc, r0]
    .1bec: 	bl	1da4 <_hwmem_uku_release>
    .1bf0: 	cmp	r0, #0
    .1bf4: 	popeq	{r3, pc}
    .1bf8: 	ldr	lr, [pc, #68]	; 1c44 <ump_arch_release+0x68>
    .1bfc: 	add	r0, pc, lr
    .1c00: 	bl	10ec <puts@plt>
    .1c04: 	ldr	r2, [pc, #60]	; 1c48 <ump_arch_release+0x6c>
    .1c08: 	add	r0, pc, r2
    .1c0c: 	bl	10f8 <printf@plt>
    .1c10: 	ldr	ip, [pc, #52]	; 1c4c <ump_arch_release+0x70>
    .1c14: 	ldr	r3, [pc, #52]	; 1c50 <ump_arch_release+0x74>
    .1c18: 	mov	r2, #167	; 0xa7
    .1c1c: 	add	r0, pc, ip
    .1c20: 	add	r1, pc, r3
    .1c24: 	bl	10f8 <printf@plt>
    .1c28: 	ldr	r1, [pc, #36]	; 1c54 <ump_arch_release+0x78>
    .1c2c: 	add	r0, pc, r1
    .1c30: 	bl	10f8 <printf@plt>
    .1c34: 	mov	r0, #10
    .1c38: 	bl	1104 <putchar@plt>
    .1c3c: 	bl	1110 <abort@plt>
    .1c40: 	andeq	r3, r0, r4, ror #8
    .1c44: 	andeq	r1, r0, r4, ror #18
    .1c48: 	andeq	r1, r0, r0, lsr #19
    .1c4c: 	muleq	r0, ip, r9
    .1c50: 	ldrdeq	r1, [r0], -r4
    .1c54: 	andeq	r1, r0, r8, lsr fp
    .
.globl ump_arch_lock
ump_arch_lock:
    .1c58: 	mov	r2, r1
    .1c5c: 	mov	r1, r0
    .1c60: 	ldr	r0, [pc, #20]	; 1c7c <ump_arch_lock+0x24>
    .1c64: 	push	{r3, lr}
    .1c68: 	ldr	r0, [pc, r0]
    .1c6c: 	bl	1de0 <_hwmem_uku_map>
    .1c70: 	cmn	r0, #1
    .1c74: 	moveq	r0, #0
    .1c78: 	pop	{r3, pc}
    .1c7c: 	andeq	r3, r0, r4, ror #7
    .
.globl ump_arch_unlock
ump_arch_unlock:
    .1c80: 	mov	r0, r1
    .1c84: 	mov	r1, r2
    .1c88: 	b	1e20 <_hwmem_uku_unmap>
    .
.globl ump_arch_unmap
ump_arch_unmap:
    .1c8c: 	b	1e20 <_hwmem_uku_unmap>
    .
.globl ump_arch_msync
ump_arch_msync:
    .1c90: 	push	{lr}		; (str lr, [sp, #-4]!)
    .1c94: 	sub	sp, sp, #36	; 0x24
    .1c98: 	ldr	r3, [sp, #44]	; 0x2c
    .1c9c: 	ldr	r1, [sp, #40]	; 0x28
    .1ca0: 	cmp	r3, #16
    .1ca4: 	str	r2, [sp, #4]
    .1ca8: 	beq	1cfc <ump_arch_msync+0x6c>
    .1cac: 	cmp	r3, #32
    .1cb0: 	movne	r2, #3
    .1cb4: 	strne	r2, [sp, #8]
    .1cb8: 	beq	1cfc <ump_arch_msync+0x6c>
    .1cbc: 	tst	r3, #32
    .1cc0: 	mov	r0, #0
    .1cc4: 	mov	r3, #1
    .1cc8: 	str	r1, [sp, #24]
    .1ccc: 	str	r1, [sp, #28]
    .1cd0: 	add	r1, sp, #4
    .1cd4: 	str	r0, [sp, #12]
    .1cd8: 	str	r0, [sp, #20]
    .1cdc: 	str	r3, [sp, #16]
    .1ce0: 	bne	1d08 <ump_arch_msync+0x78>
    .1ce4: 	ldr	lr, [pc, #44]	; 1d18 <ump_arch_msync+0x88>
    .1ce8: 	ldr	r0, [pc, lr]
    .1cec: 	bl	1e24 <_hwmem_uku_set_sync_domain>
    .1cf0: 	mov	r0, #1
    .1cf4: 	add	sp, sp, #36	; 0x24
    .1cf8: 	ldmfd	sp!, {pc}
    .1cfc: 	mov	r2, #1
    .1d00: 	str	r2, [sp, #8]
    .1d04: 	b	1cbc <ump_arch_msync+0x2c>
    .1d08: 	ldr	ip, [pc, #12]	; 1d1c <ump_arch_msync+0x8c>
    .1d0c: 	ldr	r0, [pc, ip]
    .1d10: 	bl	1e3c <_hwmem_uku_set_cpu_domain>
    .1d14: 	b	1cf0 <ump_arch_msync+0x60>
    .1d18: 	andeq	r3, r0, r4, ror #6
    .1d1c: 	andeq	r3, r0, r0, asr #6
    .
.globl _hwmem_uku_open
_hwmem_uku_open:
    .1d20: 	push	{r4, lr}
    .1d24: 	subs	r4, r0, #0
    .1d28: 	beq	1d4c <_hwmem_uku_open+0x2c>
    .1d2c: 	ldr	r0, [pc, #32]	; 1d54 <_hwmem_uku_open+0x34>
    .1d30: 	mov	r1, #2
    .1d34: 	add	r0, pc, r0
    .1d38: 	bl	111c <open@plt>
    .1d3c: 	cmn	r0, #1
    .1d40: 	strne	r0, [r4]
    .1d44: 	movne	r0, #0
    .1d48: 	pop	{r4, pc}
    .1d4c: 	mvn	r0, #0
    .1d50: 	pop	{r4, pc}
    .1d54: 	andeq	r1, r0, r0, lsl #21
    .
.globl _hwmem_uku_close
_hwmem_uku_close:
    .1d58: 	push	{r4, lr}
    .1d5c: 	subs	r4, r0, #0
    .1d60: 	beq	1d84 <_hwmem_uku_close+0x2c>
    .1d64: 	ldr	r0, [r4]
    .1d68: 	cmn	r0, #1
    .1d6c: 	popeq	{r4, pc}
    .1d70: 	bl	1128 <close@plt>
    .1d74: 	mvn	r3, #0
    .1d78: 	mov	r0, #0
    .1d7c: 	str	r3, [r4]
    .1d80: 	pop	{r4, pc}
    .1d84: 	mvn	r0, #0
    .1d88: 	pop	{r4, pc}
    .
.globl _hwmem_uku_allocate
_hwmem_uku_allocate:
    .1d8c: 	cmn	r0, #1
    .1d90: 	mov	r2, r1
    .1d94: 	bxeq	lr
    .1d98: 	movw	r1, #22273	; 0x5701
    .1d9c: 	movt	r1, #16400	; 0x4010
    .1da0: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_release
_hwmem_uku_release:
    .1da4: 	cmn	r0, #1
    .1da8: 	mov	r2, r1
    .1dac: 	bxeq	lr
    .1db0: 	movw	r1, #22275	; 0x5703
    .1db4: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_import
_hwmem_uku_import:
    .1db8: 	cmn	r0, #1
    .1dbc: 	mov	r2, r1
    .1dc0: 	bxeq	lr
    .1dc4: 	movw	r1, #22283	; 0x570b
    .1dc8: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_export
_hwmem_uku_export:
    .1dcc: 	cmn	r0, #1
    .1dd0: 	mov	r2, r1
    .1dd4: 	bxeq	lr
    .1dd8: 	movw	r1, #22282	; 0x570a
    .1ddc: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_map
_hwmem_uku_map:
    .1de0: 	cmn	r0, #1
    .1de4: 	mov	ip, r0
    .1de8: 	push	{r4, lr}
    .1dec: 	moveq	r0, r0
    .1df0: 	sub	sp, sp, #8
    .1df4: 	mov	r4, r1
    .1df8: 	beq	1e18 <_hwmem_uku_map+0x38>
    .1dfc: 	mov	r1, r2
    .1e00: 	mov	r0, #0
    .1e04: 	mov	r2, #3
    .1e08: 	mov	r3, #1
    .1e0c: 	str	ip, [sp]
    .1e10: 	str	r4, [sp, #4]
    .1e14: 	bl	1140 <mmap@plt>
    .1e18: 	add	sp, sp, #8
    .1e1c: 	pop	{r4, pc}
    .
.globl _hwmem_uku_unmap
_hwmem_uku_unmap:
    .1e20: 	b	114c <munmap@plt>
    .
.globl _hwmem_uku_set_sync_domain
_hwmem_uku_set_sync_domain:
    .1e24: 	cmn	r0, #1
    .1e28: 	mov	r2, r1
    .1e2c: 	bxeq	lr
    .1e30: 	movw	r1, #22277	; 0x5705
    .1e34: 	movt	r1, #16412	; 0x401c
    .1e38: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_set_cpu_domain
_hwmem_uku_set_cpu_domain:
    .1e3c: 	cmn	r0, #1
    .1e40: 	mov	r2, r1
    .1e44: 	bxeq	lr
    .1e48: 	movw	r1, #22276	; 0x5704
    .1e4c: 	movt	r1, #16412	; 0x401c
    .1e50: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_pin
_hwmem_uku_pin:
    .1e54: 	cmn	r0, #1
    .1e58: 	mov	r2, r1
    .1e5c: 	bxeq	lr
    .1e60: 	movw	r1, #22278	; 0x5706
    .1e64: 	movt	r1, #49160	; 0xc008
    .1e68: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_unpin
_hwmem_uku_unpin:
    .1e6c: 	cmn	r0, #1
    .1e70: 	mov	r2, r1
    .1e74: 	bxeq	lr
    .1e78: 	movw	r1, #22279	; 0x5707
    .1e7c: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_set_access
_hwmem_uku_set_access:
    .1e80: 	cmn	r0, #1
    .1e84: 	mov	r2, r1
    .1e88: 	bxeq	lr
    .1e8c: 	movw	r1, #22280	; 0x5708
    .1e90: 	movt	r1, #16396	; 0x400c
    .1e94: 	b	1134 <ioctl@plt>
    .
.globl _hwmem_uku_get_info
_hwmem_uku_get_info:
    .1e98: 	cmn	r0, #1
    .1e9c: 	mov	r2, r1
    .1ea0: 	bxeq	lr
    .1ea4: 	movw	r1, #22281	; 0x5709
    .1ea8: 	movt	r1, #49168	; 0xc010
    .1eac: 	b	1134 <ioctl@plt>
    .
.globl _ump_osu_calloc
_ump_osu_calloc:
    .1eb0: 	b	1158 <calloc@plt>
    .
.globl _ump_osu_malloc
_ump_osu_malloc:
    .1eb4: 	b	1164 <malloc@plt>
    .
.globl _ump_osu_realloc
_ump_osu_realloc:
    .1eb8: 	b	1170 <realloc@plt>
    .
.globl _ump_osu_free
_ump_osu_free:
    .1ebc: 	b	117c <free@plt>
    .
.globl _ump_osu_memcpy
_ump_osu_memcpy:
    .1ec0: 	b	1188 <memcpy@plt>
    .
.globl _ump_osu_memset
_ump_osu_memset:
    .1ec4: 	b	1194 <memset@plt>
    .
.globl _ump_osu_memcmp
_ump_osu_memcmp:
    .1ec8: 	b	11a0 <memcmp@plt>
    .
.globl _ump_osu_lock_init
_ump_osu_lock_init:
    .1ecc: 	bics	r3, r0, #65536	; 0x10000
    .1ed0: 	push	{r4, r5, r6, r7, r8, lr}
    .1ed4: 	mov	r4, r0
    .1ed8: 	sub	sp, sp, #8
    .1edc: 	mov	r5, r1
    .1ee0: 	bne	2008 <_ump_osu_lock_init+0x13c>
    .1ee4: 	cmp	r1, #0
    .1ee8: 	bne	1fc0 <_ump_osu_lock_init+0xf4>
    .1eec: 	add	r0, sp, #4
    .1ef0: 	bl	11ac <pthread_mutexattr_init@plt>
    .1ef4: 	subs	r6, r0, #0
    .1ef8: 	bne	1f54 <_ump_osu_lock_init+0x88>
    .1efc: 	add	r0, sp, #4
    .1f00: 	mov	r1, r6
    .1f04: 	bl	11b8 <pthread_mutexattr_settype@plt>
    .1f08: 	subs	r8, r0, #0
    .1f0c: 	bne	1f90 <_ump_osu_lock_init+0xc4>
    .1f10: 	mov	r0, #20
    .1f14: 	bl	1eb4 <_ump_osu_malloc>
    .1f18: 	subs	r5, r0, #0
    .1f1c: 	beq	1fb4 <_ump_osu_lock_init+0xe8>
    .1f20: 	add	r6, r5, #4
    .1f24: 	add	r1, sp, #4
    .1f28: 	mov	r0, r6
    .1f2c: 	bl	11c4 <pthread_mutex_init@plt>
    .1f30: 	subs	r7, r0, #0
    .1f34: 	add	r0, sp, #4
    .1f38: 	bne	1fa0 <_ump_osu_lock_init+0xd4>
    .1f3c: 	bl	11d0 <pthread_mutexattr_destroy@plt>
    .1f40: 	tst	r4, #65536	; 0x10000
    .1f44: 	bne	1f60 <_ump_osu_lock_init+0x94>
    .1f48: 	mvn	lr, #0
    .1f4c: 	str	r4, [r5]
    .1f50: 	str	lr, [r5, #16]
    .1f54: 	mov	r0, r5
    .1f58: 	add	sp, sp, #8
    .1f5c: 	pop	{r4, r5, r6, r7, r8, pc}
    .1f60: 	add	r0, r5, #8
    .1f64: 	mov	r1, r7
    .1f68: 	bl	11dc <pthread_cond_init@plt>
    .1f6c: 	cmp	r0, #0
    .1f70: 	streq	r0, [r5, #12]
    .1f74: 	beq	1f48 <_ump_osu_lock_init+0x7c>
    .1f78: 	mov	r0, r6
    .1f7c: 	bl	11e8 <pthread_mutex_destroy@plt>
    .1f80: 	mov	r0, r5
    .1f84: 	bl	1ebc <_ump_osu_free>
    .1f88: 	mov	r5, r7
    .1f8c: 	b	1f54 <_ump_osu_lock_init+0x88>
    .1f90: 	add	r0, sp, #4
    .1f94: 	mov	r5, r6
    .1f98: 	bl	11d0 <pthread_mutexattr_destroy@plt>
    .1f9c: 	b	1f54 <_ump_osu_lock_init+0x88>
    .1fa0: 	bl	11d0 <pthread_mutexattr_destroy@plt>
    .1fa4: 	mov	r0, r5
    .1fa8: 	bl	1ebc <_ump_osu_free>
    .1fac: 	mov	r5, r8
    .1fb0: 	b	1f54 <_ump_osu_lock_init+0x88>
    .1fb4: 	add	r0, sp, #4
    .1fb8: 	bl	11d0 <pthread_mutexattr_destroy@plt>
    .1fbc: 	b	1f54 <_ump_osu_lock_init+0x88>
    .1fc0: 	ldr	ip, [pc, #140]	; 2054 <_ump_osu_lock_init+0x188>
    .1fc4: 	ldr	r8, [pc, #140]	; 2058 <_ump_osu_lock_init+0x18c>
    .1fc8: 	add	r0, pc, ip
    .1fcc: 	ldr	r7, [pc, #136]	; 205c <_ump_osu_lock_init+0x190>
    .1fd0: 	ldr	r6, [pc, #136]	; 2060 <_ump_osu_lock_init+0x194>
    .1fd4: 	bl	10ec <puts@plt>
    .1fd8: 	ldr	r4, [pc, #132]	; 2064 <_ump_osu_lock_init+0x198>
    .1fdc: 	add	r0, pc, r8
    .1fe0: 	bl	10f8 <printf@plt>
    .1fe4: 	mov	r2, #175	; 0xaf
    .1fe8: 	add	r1, pc, r6
    .1fec: 	add	r0, pc, r7
    .1ff0: 	bl	10f8 <printf@plt>
    .1ff4: 	add	r0, pc, r4
    .1ff8: 	bl	10ec <puts@plt>
    .1ffc: 	mov	r0, #10
    .2000: 	bl	1104 <putchar@plt>
    .2004: 	bl	1110 <abort@plt>
    .2008: 	ldr	r5, [pc, #88]	; 2068 <_ump_osu_lock_init+0x19c>
    .200c: 	add	r0, pc, r5
    .2010: 	bl	10ec <puts@plt>
    .2014: 	ldr	r2, [pc, #80]	; 206c <_ump_osu_lock_init+0x1a0>
    .2018: 	add	r0, pc, r2
    .201c: 	bl	10f8 <printf@plt>
    .2020: 	ldr	r3, [pc, #72]	; 2070 <_ump_osu_lock_init+0x1a4>
    .2024: 	ldr	r1, [pc, #72]	; 2074 <_ump_osu_lock_init+0x1a8>
    .2028: 	mov	r2, #171	; 0xab
    .202c: 	add	r0, pc, r3
    .2030: 	add	r1, pc, r1
    .2034: 	bl	10f8 <printf@plt>
    .2038: 	ldr	r0, [pc, #56]	; 2078 <_ump_osu_lock_init+0x1ac>
    .203c: 	mov	r1, r4
    .2040: 	add	r0, pc, r0
    .2044: 	bl	10f8 <printf@plt>
    .2048: 	mov	r0, #10
    .204c: 	bl	1104 <putchar@plt>
    .2050: 	bl	1110 <abort@plt>
    .2054: 	andeq	r1, r0, r8, asr r8
    .2058: 	andeq	r1, r0, ip, lsl #17
    .205c: 	andeq	r1, r0, ip, lsl #17
    .2060: 	andeq	r1, r0, r4, asr #27
    .2064: 	andeq	r1, r0, r8, asr r9
    .2068: 	andeq	r1, r0, r4, lsl r8
    .206c: 	andeq	r1, r0, r0, asr r8
    .2070: 	andeq	r1, r0, ip, asr #16
    .2074: 	andeq	r1, r0, ip, ror sp
    .2078: 			; <UNDEFINED> instruction: 0x000018bc
    .
.globl _ump_osu_lock_auto_init
_ump_osu_lock_auto_init:
    .207c: 	push	{r4, r5, lr}
    .2080: 	subs	r4, r0, #0
    .2084: 	sub	sp, sp, #20
    .2088: 	beq	2204 <_ump_osu_lock_auto_init+0x188>
    .208c: 	ldr	r0, [r4]
    .2090: 	cmp	r0, #0
    .2094: 	movne	r0, #0
    .2098: 	beq	20a4 <_ump_osu_lock_auto_init+0x28>
    .209c: 	add	sp, sp, #20
    .20a0: 	pop	{r4, r5, pc}
    .20a4: 	ldr	r5, [pc, #488]	; 2294 <_ump_osu_lock_auto_init+0x218>
    .20a8: 	str	r1, [sp, #12]
    .20ac: 	add	r5, pc, r5
    .20b0: 	str	r2, [sp, #8]
    .20b4: 	str	r3, [sp, #4]
    .20b8: 	mov	r0, r5
    .20bc: 	bl	11f4 <pthread_mutex_lock@plt>
    .20c0: 	ldr	r1, [sp, #12]
    .20c4: 	ldr	r2, [sp, #8]
    .20c8: 	ldr	r3, [sp, #4]
    .20cc: 	cmp	r0, #0
    .20d0: 	bne	224c <_ump_osu_lock_auto_init+0x1d0>
    .20d4: 	ldr	ip, [r4]
    .20d8: 	cmp	ip, #0
    .20dc: 	beq	2138 <_ump_osu_lock_auto_init+0xbc>
    .20e0: 	mov	r0, r5
    .20e4: 	bl	1200 <pthread_mutex_unlock@plt>
    .20e8: 	cmp	r0, #0
    .20ec: 	beq	209c <_ump_osu_lock_auto_init+0x20>
    .20f0: 	ldr	r0, [pc, #416]	; 2298 <_ump_osu_lock_auto_init+0x21c>
    .20f4: 	ldr	r5, [pc, #416]	; 229c <_ump_osu_lock_auto_init+0x220>
    .20f8: 	add	r0, pc, r0
    .20fc: 	ldr	r4, [pc, #412]	; 22a0 <_ump_osu_lock_auto_init+0x224>
    .2100: 	bl	10ec <puts@plt>
    .2104: 	ldr	r1, [pc, #408]	; 22a4 <_ump_osu_lock_auto_init+0x228>
    .2108: 	add	r0, pc, r1
    .210c: 	bl	10f8 <printf@plt>
    .2110: 	add	r1, pc, r4
    .2114: 	mov	r2, #130	; 0x82
    .2118: 	add	r0, pc, r5
    .211c: 	bl	10f8 <printf@plt>
    .2120: 	ldr	r2, [pc, #384]	; 22a8 <_ump_osu_lock_auto_init+0x22c>
    .2124: 	add	r0, pc, r2
    .2128: 	bl	10ec <puts@plt>
    .212c: 	mov	r0, #10
    .2130: 	bl	1104 <putchar@plt>
    .2134: 	bl	1110 <abort@plt>
    .2138: 	mov	r0, r1
    .213c: 	mov	r1, r2
    .2140: 	mov	r2, r3
    .2144: 	bl	1ecc <_ump_osu_lock_init>
    .2148: 	cmp	r0, #0
    .214c: 	str	r0, [r4]
    .2150: 	mov	r0, r5
    .2154: 	beq	21ac <_ump_osu_lock_auto_init+0x130>
    .2158: 	bl	1200 <pthread_mutex_unlock@plt>
    .215c: 	cmp	r0, #0
    .2160: 	beq	209c <_ump_osu_lock_auto_init+0x20>
    .2164: 	ldr	ip, [pc, #320]	; 22ac <_ump_osu_lock_auto_init+0x230>
    .2168: 	ldr	r5, [pc, #320]	; 22b0 <_ump_osu_lock_auto_init+0x234>
    .216c: 	add	r0, pc, ip
    .2170: 	bl	10ec <puts@plt>
    .2174: 	ldr	r3, [pc, #312]	; 22b4 <_ump_osu_lock_auto_init+0x238>
    .2178: 	add	r0, pc, r3
    .217c: 	bl	10f8 <printf@plt>
    .2180: 	ldr	r0, [pc, #304]	; 22b8 <_ump_osu_lock_auto_init+0x23c>
    .2184: 	ldr	r1, [pc, #304]	; 22bc <_ump_osu_lock_auto_init+0x240>
    .2188: 	mov	r2, #153	; 0x99
    .218c: 	add	r0, pc, r0
    .2190: 	add	r1, pc, r1
    .2194: 	bl	10f8 <printf@plt>
    .2198: 	add	r0, pc, r5
    .219c: 	bl	10ec <puts@plt>
    .21a0: 	mov	r0, #10
    .21a4: 	bl	1104 <putchar@plt>
    .21a8: 	bl	1110 <abort@plt>
    .21ac: 	bl	1200 <pthread_mutex_unlock@plt>
    .21b0: 	cmp	r0, #0
    .21b4: 	mvneq	r0, #0
    .21b8: 	beq	209c <_ump_osu_lock_auto_init+0x20>
    .21bc: 	ldr	lr, [pc, #252]	; 22c0 <_ump_osu_lock_auto_init+0x244>
    .21c0: 	ldr	r4, [pc, #252]	; 22c4 <_ump_osu_lock_auto_init+0x248>
    .21c4: 	add	r0, pc, lr
    .21c8: 	bl	10ec <puts@plt>
    .21cc: 	ldr	r2, [pc, #244]	; 22c8 <_ump_osu_lock_auto_init+0x24c>
    .21d0: 	add	r0, pc, r2
    .21d4: 	bl	10f8 <printf@plt>
    .21d8: 	ldr	ip, [pc, #236]	; 22cc <_ump_osu_lock_auto_init+0x250>
    .21dc: 	mov	r2, #143	; 0x8f
    .21e0: 	add	r0, pc, r4
    .21e4: 	add	r1, pc, ip
    .21e8: 	bl	10f8 <printf@plt>
    .21ec: 	ldr	r3, [pc, #220]	; 22d0 <_ump_osu_lock_auto_init+0x254>
    .21f0: 	add	r0, pc, r3
    .21f4: 	bl	10ec <puts@plt>
    .21f8: 	mov	r0, #10
    .21fc: 	bl	1104 <putchar@plt>
    .2200: 	bl	1110 <abort@plt>
    .2204: 	ldr	r4, [pc, #200]	; 22d4 <_ump_osu_lock_auto_init+0x258>
    .2208: 	add	r0, pc, r4
    .220c: 	bl	10ec <puts@plt>
    .2210: 	ldr	r2, [pc, #192]	; 22d8 <_ump_osu_lock_auto_init+0x25c>
    .2214: 	add	r0, pc, r2
    .2218: 	bl	10f8 <printf@plt>
    .221c: 	ldr	r3, [pc, #184]	; 22dc <_ump_osu_lock_auto_init+0x260>
    .2220: 	ldr	r1, [pc, #184]	; 22e0 <_ump_osu_lock_auto_init+0x264>
    .2224: 	mov	r2, #107	; 0x6b
    .2228: 	add	r0, pc, r3
    .222c: 	add	r1, pc, r1
    .2230: 	bl	10f8 <printf@plt>
    .2234: 	ldr	r0, [pc, #168]	; 22e4 <_ump_osu_lock_auto_init+0x268>
    .2238: 	add	r0, pc, r0
    .223c: 	bl	10f8 <printf@plt>
    .2240: 	mov	r0, #10
    .2244: 	bl	1104 <putchar@plt>
    .2248: 	bl	1110 <abort@plt>
    .224c: 	ldr	lr, [pc, #148]	; 22e8 <_ump_osu_lock_auto_init+0x26c>
    .2250: 	add	r0, pc, lr
    .2254: 	bl	10ec <puts@plt>
    .2258: 	ldr	r3, [pc, #140]	; 22ec <_ump_osu_lock_auto_init+0x270>
    .225c: 	add	r0, pc, r3
    .2260: 	bl	10f8 <printf@plt>
    .2264: 	ldr	r0, [pc, #132]	; 22f0 <_ump_osu_lock_auto_init+0x274>
    .2268: 	ldr	r1, [pc, #132]	; 22f4 <_ump_osu_lock_auto_init+0x278>
    .226c: 	mov	r2, #119	; 0x77
    .2270: 	add	r0, pc, r0
    .2274: 	add	r1, pc, r1
    .2278: 	bl	10f8 <printf@plt>
    .227c: 	ldr	ip, [pc, #116]	; 22f8 <_ump_osu_lock_auto_init+0x27c>
    .2280: 	add	r0, pc, ip
    .2284: 	bl	10ec <puts@plt>
    .2288: 	mov	r0, #10
    .228c: 	bl	1104 <putchar@plt>
    .2290: 	bl	1110 <abort@plt>
    .2294: 	andeq	r2, r0, r8, lsr #31
    .2298: 	andeq	r1, r0, r8, lsr #14
    .229c: 	andeq	r1, r0, r0, ror #14
    .22a0: 	andeq	r1, r0, ip, ror #24
    .22a4: 	andeq	r1, r0, r0, ror #14
    .22a8: 	andeq	r1, r0, r4, ror r8
    .22ac: 			; <UNDEFINED> instruction: 0x000016b4
    .22b0: 	andeq	r1, r0, r0, lsl #16
    .22b4: 	strdeq	r1, [r0], -r0
    .22b8: 	andeq	r1, r0, ip, ror #13
    .22bc: 	andeq	r1, r0, ip, ror #23
    .22c0: 	andeq	r1, r0, ip, asr r6
    .22c4: 	muleq	r0, r8, r6
    .22c8: 	muleq	r0, r8, r6
    .22cc: 	muleq	r0, r8, fp
    .22d0: 	andeq	r1, r0, r8, lsr #15
    .22d4: 	andeq	r1, r0, r8, lsl r6
    .22d8: 	andeq	r1, r0, r4, asr r6
    .22dc: 	andeq	r1, r0, r0, asr r6
    .22e0: 	andeq	r1, r0, r0, asr fp
    .22e4: 	andeq	r1, r0, ip, lsr #14
    .22e8: 	ldrdeq	r1, [r0], -r0
    .22ec: 	andeq	r1, r0, ip, lsl #12
    .22f0: 	andeq	r1, r0, r8, lsl #12
    .22f4: 	andeq	r1, r0, r8, lsl #22
    .22f8: 	strdeq	r1, [r0], -r8
    .
.globl _ump_osu_lock_timed_wait
_ump_osu_lock_timed_wait:
    .22fc: 	push	{r4, r5, r6, lr}
    .2300: 	subs	r4, r0, #0
    .2304: 	sub	sp, sp, #16
    .2308: 	mov	r5, r1
    .230c: 	mov	r6, r2
    .2310: 	beq	24c4 <_ump_osu_lock_timed_wait+0x1c8>
    .2314: 	cmp	r1, #0
    .2318: 	bne	2478 <_ump_osu_lock_timed_wait+0x17c>
    .231c: 	ldr	r3, [r4]
    .2320: 	cmp	r3, #65536	; 0x10000
    .2324: 	bne	250c <_ump_osu_lock_timed_wait+0x210>
    .2328: 	add	r0, sp, #8
    .232c: 	bl	120c <gettimeofday@plt>
    .2330: 	cmp	r0, #0
    .2334: 	bne	241c <_ump_osu_lock_timed_wait+0x120>
    .2338: 	ldr	r0, [sp, #12]
    .233c: 	movw	r2, #16959	; 0x423f
    .2340: 	movt	r2, #15
    .2344: 	ldr	r3, [sp, #8]
    .2348: 	add	r6, r0, r6
    .234c: 	str	r6, [sp, #12]
    .2350: 	cmp	r6, r2
    .2354: 	ble	2374 <_ump_osu_lock_timed_wait+0x78>
    .2358: 	sub	lr, r6, #999424	; 0xf4000
    .235c: 	add	r3, r3, #1
    .2360: 	sub	r6, lr, #576	; 0x240
    .2364: 	cmp	r6, r2
    .2368: 	bgt	2358 <_ump_osu_lock_timed_wait+0x5c>
    .236c: 	str	r6, [sp, #12]
    .2370: 	str	r3, [sp, #8]
    .2374: 	mov	r2, #1000	; 0x3e8
    .2378: 	add	r5, r4, #4
    .237c: 	mul	r1, r2, r6
    .2380: 	mov	r0, r5
    .2384: 	str	r3, [sp]
    .2388: 	add	r6, r4, #8
    .238c: 	str	r1, [sp, #4]
    .2390: 	bl	11f4 <pthread_mutex_lock@plt>
    .2394: 	ldr	ip, [r4, #12]
    .2398: 	cmp	ip, #1
    .239c: 	bne	23f0 <_ump_osu_lock_timed_wait+0xf4>
    .23a0: 	mov	r1, r5
    .23a4: 	mov	r0, r6
    .23a8: 	mov	r2, sp
    .23ac: 	bl	1218 <pthread_cond_timedwait@plt>
    .23b0: 	subs	r1, r0, #0
    .23b4: 	beq	2394 <_ump_osu_lock_timed_wait+0x98>
    .23b8: 	cmp	r1, #110	; 0x6e
    .23bc: 	beq	23e0 <_ump_osu_lock_timed_wait+0xe4>
    .23c0: 	ldr	r3, [pc, #396]	; 2554 <_ump_osu_lock_timed_wait+0x258>
    .23c4: 	add	r0, pc, r3
    .23c8: 	bl	10f8 <printf@plt>
    .23cc: 	mov	r0, r5
    .23d0: 	bl	1200 <pthread_mutex_unlock@plt>
    .23d4: 	mvn	r0, #0
    .23d8: 	add	sp, sp, #16
    .23dc: 	pop	{r4, r5, r6, pc}
    .23e0: 	mov	r0, r5
    .23e4: 	bl	1200 <pthread_mutex_unlock@plt>
    .23e8: 	mvn	r0, #1
    .23ec: 	b	23d8 <_ump_osu_lock_timed_wait+0xdc>
    .23f0: 	ldr	r6, [r4, #16]
    .23f4: 	cmn	r6, #1
    .23f8: 	bne	2430 <_ump_osu_lock_timed_wait+0x134>
    .23fc: 	mov	r6, #0
    .2400: 	mov	r2, #1
    .2404: 	str	r6, [r4, #16]
    .2408: 	mov	r0, r5
    .240c: 	str	r2, [r4, #12]
    .2410: 	bl	1200 <pthread_mutex_unlock@plt>
    .2414: 	mov	r0, r6
    .2418: 	b	23d8 <_ump_osu_lock_timed_wait+0xdc>
    .241c: 	ldr	ip, [pc, #308]	; 2558 <_ump_osu_lock_timed_wait+0x25c>
    .2420: 	add	r0, pc, ip
    .2424: 	bl	10f8 <printf@plt>
    .2428: 	mvn	r0, #0
    .242c: 	b	23d8 <_ump_osu_lock_timed_wait+0xdc>
    .2430: 	ldr	lr, [pc, #292]	; 255c <_ump_osu_lock_timed_wait+0x260>
    .2434: 	ldr	r5, [pc, #292]	; 2560 <_ump_osu_lock_timed_wait+0x264>
    .2438: 	add	r0, pc, lr
    .243c: 	ldr	r4, [pc, #288]	; 2564 <_ump_osu_lock_timed_wait+0x268>
    .2440: 	bl	10ec <puts@plt>
    .2444: 	ldr	r1, [pc, #284]	; 2568 <_ump_osu_lock_timed_wait+0x26c>
    .2448: 	add	r0, pc, r1
    .244c: 	bl	10f8 <printf@plt>
    .2450: 	ldr	r0, [pc, #276]	; 256c <_ump_osu_lock_timed_wait+0x270>
    .2454: 	movw	r2, #307	; 0x133
    .2458: 	add	r1, pc, r5
    .245c: 	add	r0, pc, r0
    .2460: 	bl	10f8 <printf@plt>
    .2464: 	add	r0, pc, r4
    .2468: 	bl	10ec <puts@plt>
    .246c: 	mov	r0, #10
    .2470: 	bl	1104 <putchar@plt>
    .2474: 	bl	1110 <abort@plt>
    .2478: 	ldr	lr, [pc, #240]	; 2570 <_ump_osu_lock_timed_wait+0x274>
    .247c: 	ldr	r6, [pc, #240]	; 2574 <_ump_osu_lock_timed_wait+0x278>
    .2480: 	add	r0, pc, lr
    .2484: 	bl	10ec <puts@plt>
    .2488: 	ldr	r0, [pc, #232]	; 2578 <_ump_osu_lock_timed_wait+0x27c>
    .248c: 	add	r0, pc, r0
    .2490: 	bl	10f8 <printf@plt>
    .2494: 	ldr	ip, [pc, #224]	; 257c <_ump_osu_lock_timed_wait+0x280>
    .2498: 	mov	r2, #250	; 0xfa
    .249c: 	add	r1, pc, r6
    .24a0: 	add	r0, pc, ip
    .24a4: 	bl	10f8 <printf@plt>
    .24a8: 	mov	r1, r5
    .24ac: 	ldr	r5, [pc, #204]	; 2580 <_ump_osu_lock_timed_wait+0x284>
    .24b0: 	add	r0, pc, r5
    .24b4: 	bl	10f8 <printf@plt>
    .24b8: 	mov	r0, #10
    .24bc: 	bl	1104 <putchar@plt>
    .24c0: 	bl	1110 <abort@plt>
    .24c4: 	ldr	r4, [pc, #184]	; 2584 <_ump_osu_lock_timed_wait+0x288>
    .24c8: 	add	r0, pc, r4
    .24cc: 	bl	10ec <puts@plt>
    .24d0: 	ldr	r2, [pc, #176]	; 2588 <_ump_osu_lock_timed_wait+0x28c>
    .24d4: 	add	r0, pc, r2
    .24d8: 	bl	10f8 <printf@plt>
    .24dc: 	ldr	r3, [pc, #168]	; 258c <_ump_osu_lock_timed_wait+0x290>
    .24e0: 	ldr	r1, [pc, #168]	; 2590 <_ump_osu_lock_timed_wait+0x294>
    .24e4: 	mov	r2, #247	; 0xf7
    .24e8: 	add	r0, pc, r3
    .24ec: 	add	r1, pc, r1
    .24f0: 	bl	10f8 <printf@plt>
    .24f4: 	ldr	r0, [pc, #152]	; 2594 <_ump_osu_lock_timed_wait+0x298>
    .24f8: 	add	r0, pc, r0
    .24fc: 	bl	10f8 <printf@plt>
    .2500: 	mov	r0, #10
    .2504: 	bl	1104 <putchar@plt>
    .2508: 	bl	1110 <abort@plt>
    .250c: 	ldr	r6, [pc, #132]	; 2598 <_ump_osu_lock_timed_wait+0x29c>
    .2510: 	ldr	r5, [pc, #132]	; 259c <_ump_osu_lock_timed_wait+0x2a0>
    .2514: 	add	r0, pc, r6
    .2518: 	ldr	r4, [pc, #128]	; 25a0 <_ump_osu_lock_timed_wait+0x2a4>
    .251c: 	bl	10ec <puts@plt>
    .2520: 	ldr	r2, [pc, #124]	; 25a4 <_ump_osu_lock_timed_wait+0x2a8>
    .2524: 	add	r0, pc, r2
    .2528: 	bl	10f8 <printf@plt>
    .252c: 	mov	r2, #251	; 0xfb
    .2530: 	add	r1, pc, r4
    .2534: 	add	r0, pc, r5
    .2538: 	bl	10f8 <printf@plt>
    .253c: 	ldr	r1, [pc, #100]	; 25a8 <_ump_osu_lock_timed_wait+0x2ac>
    .2540: 	add	r0, pc, r1
    .2544: 	bl	10f8 <printf@plt>
    .2548: 	mov	r0, #10
    .254c: 	bl	1104 <putchar@plt>
    .2550: 	bl	1110 <abort@plt>
    .2554: 	ldrdeq	r1, [r0], -r4
    .2558: 	andeq	r1, r0, r8, lsl #12
    .255c: 	andeq	r1, r0, r8, ror #7
    .2560: 	andeq	r1, r0, r8, ror #6
    .2564: 	andeq	r1, r0, ip, ror #12
    .2568: 	andeq	r1, r0, r0, lsr #8
    .256c: 	andeq	r1, r0, ip, lsl r4
    .2570: 	andeq	r1, r0, r0, lsr #7
    .2574: 	andeq	r1, r0, r4, lsr #6
    .2578: 	ldrdeq	r1, [r0], -ip
    .257c: 	ldrdeq	r1, [r0], -r8
    .2580: 	andeq	r1, r0, r0, lsr #10
    .2584: 	andeq	r1, r0, r8, asr r3
    .2588: 	muleq	r0, r4, r3
    .258c: 	muleq	r0, r0, r3
    .2590: 	ldrdeq	r1, [r0], -r4
    .2594: 	andeq	r1, r0, r4, asr #9
    .2598: 	andeq	r1, r0, ip, lsl #6
    .259c: 	andeq	r1, r0, r4, asr #6
    .25a0: 	muleq	r0, r0, r2
    .25a4: 	andeq	r1, r0, r4, asr #6
    .25a8: 	andeq	r1, r0, ip, lsr #9
    .
.globl _ump_osu_lock_wait
_ump_osu_lock_wait:
    .25ac: 	push	{r4, r5, r6, lr}
    .25b0: 	subs	r4, r0, #0
    .25b4: 	mov	r5, r1
    .25b8: 	beq	2744 <_ump_osu_lock_wait+0x198>
    .25bc: 	cmp	r1, #0
    .25c0: 	bne	26f8 <_ump_osu_lock_wait+0x14c>
    .25c4: 	ldr	r3, [r4]
    .25c8: 	cmp	r3, #65536	; 0x10000
    .25cc: 	beq	2698 <_ump_osu_lock_wait+0xec>
    .25d0: 	cmp	r3, #131072	; 0x20000
    .25d4: 	beq	25e0 <_ump_osu_lock_wait+0x34>
    .25d8: 	cmp	r3, #0
    .25dc: 	bne	2648 <_ump_osu_lock_wait+0x9c>
    .25e0: 	add	r0, r4, #4
    .25e4: 	bl	11f4 <pthread_mutex_lock@plt>
    .25e8: 	subs	r5, r0, #0
    .25ec: 	bne	278c <_ump_osu_lock_wait+0x1e0>
    .25f0: 	ldr	ip, [r4, #16]
    .25f4: 	cmn	ip, #1
    .25f8: 	streq	r5, [r4, #16]
    .25fc: 	beq	2690 <_ump_osu_lock_wait+0xe4>
    .2600: 	ldr	lr, [pc, #536]	; 2820 <_ump_osu_lock_wait+0x274>
    .2604: 	ldr	r5, [pc, #536]	; 2824 <_ump_osu_lock_wait+0x278>
    .2608: 	add	r0, pc, lr
    .260c: 	bl	10ec <puts@plt>
    .2610: 	ldr	r1, [pc, #528]	; 2828 <_ump_osu_lock_wait+0x27c>
    .2614: 	add	r0, pc, r1
    .2618: 	bl	10f8 <printf@plt>
    .261c: 	ldr	r3, [pc, #520]	; 282c <_ump_osu_lock_wait+0x280>
    .2620: 	ldr	r0, [pc, #520]	; 2830 <_ump_osu_lock_wait+0x284>
    .2624: 	movw	r2, #345	; 0x159
    .2628: 	add	r1, pc, r3
    .262c: 	add	r0, pc, r0
    .2630: 	bl	10f8 <printf@plt>
    .2634: 	add	r0, pc, r5
    .2638: 	bl	10ec <puts@plt>
    .263c: 	mov	r0, #10
    .2640: 	bl	1104 <putchar@plt>
    .2644: 	bl	1110 <abort@plt>
    .2648: 	ldr	lr, [pc, #484]	; 2834 <_ump_osu_lock_wait+0x288>
    .264c: 	add	r0, pc, lr
    .2650: 	bl	10ec <puts@plt>
    .2654: 	ldr	r1, [pc, #476]	; 2838 <_ump_osu_lock_wait+0x28c>
    .2658: 	add	r0, pc, r1
    .265c: 	bl	10f8 <printf@plt>
    .2660: 	ldr	r3, [pc, #468]	; 283c <_ump_osu_lock_wait+0x290>
    .2664: 	ldr	r0, [pc, #468]	; 2840 <_ump_osu_lock_wait+0x294>
    .2668: 	movw	r2, #371	; 0x173
    .266c: 	add	r1, pc, r3
    .2670: 	add	r0, pc, r0
    .2674: 	bl	10f8 <printf@plt>
    .2678: 	ldr	ip, [pc, #452]	; 2844 <_ump_osu_lock_wait+0x298>
    .267c: 	ldr	r1, [r4]
    .2680: 	add	r0, pc, ip
    .2684: 	bl	10f8 <printf@plt>
    .2688: 	mov	r0, #10
    .268c: 	bl	1104 <putchar@plt>
    .2690: 	mov	r0, #0
    .2694: 	pop	{r4, r5, r6, pc}
    .2698: 	add	r5, r4, #4
    .269c: 	mov	r0, r5
    .26a0: 	bl	11f4 <pthread_mutex_lock@plt>
    .26a4: 	ldr	r2, [r4, #12]
    .26a8: 	cmp	r2, #1
    .26ac: 	bne	26cc <_ump_osu_lock_wait+0x120>
    .26b0: 	add	r6, r4, #8
    .26b4: 	mov	r0, r6
    .26b8: 	mov	r1, r5
    .26bc: 	bl	1224 <pthread_cond_wait@plt>
    .26c0: 	ldr	ip, [r4, #12]
    .26c4: 	cmp	ip, #1
    .26c8: 	beq	26b4 <_ump_osu_lock_wait+0x108>
    .26cc: 	ldr	r3, [r4, #16]
    .26d0: 	cmn	r3, #1
    .26d4: 	bne	27d8 <_ump_osu_lock_wait+0x22c>
    .26d8: 	mov	r2, #0
    .26dc: 	mov	lr, #1
    .26e0: 	str	r2, [r4, #16]
    .26e4: 	mov	r0, r5
    .26e8: 	str	lr, [r4, #12]
    .26ec: 	bl	1200 <pthread_mutex_unlock@plt>
    .26f0: 	mov	r0, #0
    .26f4: 	pop	{r4, r5, r6, pc}
    .26f8: 	ldr	lr, [pc, #328]	; 2848 <_ump_osu_lock_wait+0x29c>
    .26fc: 	ldr	r6, [pc, #328]	; 284c <_ump_osu_lock_wait+0x2a0>
    .2700: 	add	r0, pc, lr
    .2704: 	bl	10ec <puts@plt>
    .2708: 	ldr	r0, [pc, #320]	; 2850 <_ump_osu_lock_wait+0x2a4>
    .270c: 	add	r0, pc, r0
    .2710: 	bl	10f8 <printf@plt>
    .2714: 	ldr	ip, [pc, #312]	; 2854 <_ump_osu_lock_wait+0x2a8>
    .2718: 	movw	r2, #325	; 0x145
    .271c: 	add	r1, pc, r6
    .2720: 	add	r0, pc, ip
    .2724: 	bl	10f8 <printf@plt>
    .2728: 	mov	r1, r5
    .272c: 	ldr	r5, [pc, #292]	; 2858 <_ump_osu_lock_wait+0x2ac>
    .2730: 	add	r0, pc, r5
    .2734: 	bl	10f8 <printf@plt>
    .2738: 	mov	r0, #10
    .273c: 	bl	1104 <putchar@plt>
    .2740: 	bl	1110 <abort@plt>
    .2744: 	ldr	r4, [pc, #272]	; 285c <_ump_osu_lock_wait+0x2b0>
    .2748: 	add	r0, pc, r4
    .274c: 	bl	10ec <puts@plt>
    .2750: 	ldr	r2, [pc, #264]	; 2860 <_ump_osu_lock_wait+0x2b4>
    .2754: 	add	r0, pc, r2
    .2758: 	bl	10f8 <printf@plt>
    .275c: 	ldr	r3, [pc, #256]	; 2864 <_ump_osu_lock_wait+0x2b8>
    .2760: 	ldr	r1, [pc, #256]	; 2868 <_ump_osu_lock_wait+0x2bc>
    .2764: 	movw	r2, #322	; 0x142
    .2768: 	add	r0, pc, r3
    .276c: 	add	r1, pc, r1
    .2770: 	bl	10f8 <printf@plt>
    .2774: 	ldr	r0, [pc, #240]	; 286c <_ump_osu_lock_wait+0x2c0>
    .2778: 	add	r0, pc, r0
    .277c: 	bl	10f8 <printf@plt>
    .2780: 	mov	r0, #10
    .2784: 	bl	1104 <putchar@plt>
    .2788: 	bl	1110 <abort@plt>
    .278c: 	ldr	r6, [pc, #220]	; 2870 <_ump_osu_lock_wait+0x2c4>
    .2790: 	ldr	r4, [pc, #220]	; 2874 <_ump_osu_lock_wait+0x2c8>
    .2794: 	add	r0, pc, r6
    .2798: 	bl	10ec <puts@plt>
    .279c: 	ldr	r2, [pc, #212]	; 2878 <_ump_osu_lock_wait+0x2cc>
    .27a0: 	add	r0, pc, r2
    .27a4: 	bl	10f8 <printf@plt>
    .27a8: 	ldr	r1, [pc, #204]	; 287c <_ump_osu_lock_wait+0x2d0>
    .27ac: 	movw	r2, #339	; 0x153
    .27b0: 	add	r0, pc, r4
    .27b4: 	add	r1, pc, r1
    .27b8: 	bl	10f8 <printf@plt>
    .27bc: 	ldr	r3, [pc, #188]	; 2880 <_ump_osu_lock_wait+0x2d4>
    .27c0: 	mov	r1, r5
    .27c4: 	add	r0, pc, r3
    .27c8: 	bl	10f8 <printf@plt>
    .27cc: 	mov	r0, #10
    .27d0: 	bl	1104 <putchar@plt>
    .27d4: 	bl	1110 <abort@plt>
    .27d8: 	ldr	r1, [pc, #164]	; 2884 <_ump_osu_lock_wait+0x2d8>
    .27dc: 	ldr	r5, [pc, #164]	; 2888 <_ump_osu_lock_wait+0x2dc>
    .27e0: 	add	r0, pc, r1
    .27e4: 	ldr	r6, [pc, #160]	; 288c <_ump_osu_lock_wait+0x2e0>
    .27e8: 	bl	10ec <puts@plt>
    .27ec: 	ldr	r0, [pc, #156]	; 2890 <_ump_osu_lock_wait+0x2e4>
    .27f0: 	ldr	r4, [pc, #156]	; 2894 <_ump_osu_lock_wait+0x2e8>
    .27f4: 	add	r0, pc, r0
    .27f8: 	bl	10f8 <printf@plt>
    .27fc: 	movw	r2, #361	; 0x169
    .2800: 	add	r1, pc, r6
    .2804: 	add	r0, pc, r5
    .2808: 	bl	10f8 <printf@plt>
    .280c: 	add	r0, pc, r4
    .2810: 	bl	10ec <puts@plt>
    .2814: 	mov	r0, #10
    .2818: 	bl	1104 <putchar@plt>
    .281c: 	bl	1110 <abort@plt>
    .2820: 	andeq	r1, r0, r8, lsl r2
    .2824: 	muleq	r0, ip, r4
    .2828: 	andeq	r1, r0, r4, asr r2
    .282c: 			; <UNDEFINED> instruction: 0x000011b4
    .2830: 	andeq	r1, r0, ip, asr #4
    .2834: 	ldrdeq	r1, [r0], -r4
    .2838: 	andeq	r1, r0, ip, asr #9
    .283c: 	andeq	r1, r0, r0, ror r1
    .2840: 	andeq	r1, r0, r8, lsl #4
    .2844: 	andeq	r1, r0, ip, lsr #9
    .2848: 	andeq	r1, r0, r0, lsr #2
    .284c: 	andeq	r1, r0, r0, asr #1
    .2850: 	andeq	r1, r0, ip, asr r1
    .2854: 	andeq	r1, r0, r8, asr r1
    .2858: 	andeq	r1, r0, r0, lsr #5
    .285c: 	ldrdeq	r1, [r0], -r8
    .2860: 	andeq	r1, r0, r4, lsl r1
    .2864: 	andeq	r1, r0, r0, lsl r1
    .2868: 	andeq	r1, r0, r0, ror r0
    .286c: 	andeq	r1, r0, r4, asr #4
    .2870: 	andeq	r1, r0, ip, lsl #1
    .2874: 	andeq	r1, r0, r8, asr #1
    .2878: 	andeq	r1, r0, r8, asr #1
    .287c: 	andeq	r1, r0, r8, lsr #32
    .2880: 	andeq	r1, r0, ip, lsr #6
    .2884: 	andeq	r1, r0, r0, asr #32
    .2888: 	andeq	r1, r0, r4, ror r0
    .288c: 	ldrdeq	r0, [r0], -ip
    .2890: 	andeq	r1, r0, r4, ror r0
    .2894: 	andeq	r1, r0, r4, asr #5
    .
.globl _ump_osu_lock_trywait
_ump_osu_lock_trywait:
    .2898: 	push	{r4, r5, r6, lr}
    .289c: 	subs	r4, r0, #0
    .28a0: 	mov	r5, r1
    .28a4: 	beq	29f4 <_ump_osu_lock_trywait+0x15c>
    .28a8: 	cmp	r1, #0
    .28ac: 	bne	29a8 <_ump_osu_lock_trywait+0x110>
    .28b0: 	ldr	r3, [r4]
    .28b4: 	cmp	r3, #65536	; 0x10000
    .28b8: 	beq	2954 <_ump_osu_lock_trywait+0xbc>
    .28bc: 	cmp	r3, #131072	; 0x20000
    .28c0: 	beq	28cc <_ump_osu_lock_trywait+0x34>
    .28c4: 	cmp	r3, #0
    .28c8: 	bne	2900 <_ump_osu_lock_trywait+0x68>
    .28cc: 	add	r0, r4, #4
    .28d0: 	bl	1230 <pthread_mutex_trylock@plt>
    .28d4: 	subs	r5, r0, #0
    .28d8: 	bne	29a0 <_ump_osu_lock_trywait+0x108>
    .28dc: 	ldr	r3, [r4, #16]
    .28e0: 	cmn	r3, #1
    .28e4: 	beq	28f0 <_ump_osu_lock_trywait+0x58>
    .28e8: 	cmp	r3, #0
    .28ec: 	bne	2a3c <_ump_osu_lock_trywait+0x1a4>
    .28f0: 	mov	r5, #0
    .28f4: 	str	r5, [r4, #16]
    .28f8: 	mov	r0, r5
    .28fc: 	pop	{r4, r5, r6, pc}
    .2900: 	ldr	lr, [pc, #468]	; 2adc <_ump_osu_lock_trywait+0x244>
    .2904: 	mvn	r5, #0
    .2908: 	add	r0, pc, lr
    .290c: 	bl	10ec <puts@plt>
    .2910: 	ldr	r1, [pc, #456]	; 2ae0 <_ump_osu_lock_trywait+0x248>
    .2914: 	add	r0, pc, r1
    .2918: 	bl	10f8 <printf@plt>
    .291c: 	ldr	r3, [pc, #448]	; 2ae4 <_ump_osu_lock_trywait+0x24c>
    .2920: 	ldr	r0, [pc, #448]	; 2ae8 <_ump_osu_lock_trywait+0x250>
    .2924: 	movw	r2, #438	; 0x1b6
    .2928: 	add	r1, pc, r3
    .292c: 	add	r0, pc, r0
    .2930: 	bl	10f8 <printf@plt>
    .2934: 	ldr	ip, [pc, #432]	; 2aec <_ump_osu_lock_trywait+0x254>
    .2938: 	ldr	r1, [r4]
    .293c: 	add	r0, pc, ip
    .2940: 	bl	10f8 <printf@plt>
    .2944: 	mov	r0, #10
    .2948: 	bl	1104 <putchar@plt>
    .294c: 	mov	r0, r5
    .2950: 	pop	{r4, r5, r6, pc}
    .2954: 	add	r6, r4, #4
    .2958: 	mov	r0, r6
    .295c: 	bl	11f4 <pthread_mutex_lock@plt>
    .2960: 	ldr	r5, [r4, #12]
    .2964: 	ldr	r3, [r4, #16]
    .2968: 	cmp	r5, #0
    .296c: 	moveq	r0, #1
    .2970: 	mvnne	r5, #0
    .2974: 	streq	r0, [r4, #12]
    .2978: 	cmn	r3, #1
    .297c: 	beq	2988 <_ump_osu_lock_trywait+0xf0>
    .2980: 	cmp	r3, #0
    .2984: 	bne	2a8c <_ump_osu_lock_trywait+0x1f4>
    .2988: 	mov	r2, #0
    .298c: 	mov	r0, r6
    .2990: 	str	r2, [r4, #16]
    .2994: 	bl	1200 <pthread_mutex_unlock@plt>
    .2998: 	mov	r0, r5
    .299c: 	pop	{r4, r5, r6, pc}
    .29a0: 	mvn	r5, #0
    .29a4: 	b	294c <_ump_osu_lock_trywait+0xb4>
    .29a8: 	ldr	lr, [pc, #320]	; 2af0 <_ump_osu_lock_trywait+0x258>
    .29ac: 	ldr	r6, [pc, #320]	; 2af4 <_ump_osu_lock_trywait+0x25c>
    .29b0: 	add	r0, pc, lr
    .29b4: 	bl	10ec <puts@plt>
    .29b8: 	ldr	r0, [pc, #312]	; 2af8 <_ump_osu_lock_trywait+0x260>
    .29bc: 	add	r0, pc, r0
    .29c0: 	bl	10f8 <printf@plt>
    .29c4: 	ldr	ip, [pc, #304]	; 2afc <_ump_osu_lock_trywait+0x264>
    .29c8: 	movw	r2, #385	; 0x181
    .29cc: 	add	r1, pc, r6
    .29d0: 	add	r0, pc, ip
    .29d4: 	bl	10f8 <printf@plt>
    .29d8: 	mov	r1, r5
    .29dc: 	ldr	r5, [pc, #284]	; 2b00 <_ump_osu_lock_trywait+0x268>
    .29e0: 	add	r0, pc, r5
    .29e4: 	bl	10f8 <printf@plt>
    .29e8: 	mov	r0, #10
    .29ec: 	bl	1104 <putchar@plt>
    .29f0: 	bl	1110 <abort@plt>
    .29f4: 	ldr	r4, [pc, #264]	; 2b04 <_ump_osu_lock_trywait+0x26c>
    .29f8: 	add	r0, pc, r4
    .29fc: 	bl	10ec <puts@plt>
    .2a00: 	ldr	r2, [pc, #256]	; 2b08 <_ump_osu_lock_trywait+0x270>
    .2a04: 	add	r0, pc, r2
    .2a08: 	bl	10f8 <printf@plt>
    .2a0c: 	ldr	r3, [pc, #248]	; 2b0c <_ump_osu_lock_trywait+0x274>
    .2a10: 	ldr	r1, [pc, #248]	; 2b10 <_ump_osu_lock_trywait+0x278>
    .2a14: 	movw	r2, #382	; 0x17e
    .2a18: 	add	r0, pc, r3
    .2a1c: 	add	r1, pc, r1
    .2a20: 	bl	10f8 <printf@plt>
    .2a24: 	ldr	r0, [pc, #232]	; 2b14 <_ump_osu_lock_trywait+0x27c>
    .2a28: 	add	r0, pc, r0
    .2a2c: 	bl	10f8 <printf@plt>
    .2a30: 	mov	r0, #10
    .2a34: 	bl	1104 <putchar@plt>
    .2a38: 	bl	1110 <abort@plt>
    .2a3c: 	ldr	ip, [pc, #212]	; 2b18 <_ump_osu_lock_trywait+0x280>
    .2a40: 	ldr	r6, [pc, #212]	; 2b1c <_ump_osu_lock_trywait+0x284>
    .2a44: 	add	r0, pc, ip
    .2a48: 	bl	10ec <puts@plt>
    .2a4c: 	ldr	r2, [pc, #204]	; 2b20 <_ump_osu_lock_trywait+0x288>
    .2a50: 	add	r0, pc, r2
    .2a54: 	bl	10f8 <printf@plt>
    .2a58: 	ldr	r1, [pc, #196]	; 2b24 <_ump_osu_lock_trywait+0x28c>
    .2a5c: 	mov	r2, #404	; 0x194
    .2a60: 	add	r0, pc, r6
    .2a64: 	add	r1, pc, r1
    .2a68: 	bl	10f8 <printf@plt>
    .2a6c: 	ldr	r3, [pc, #180]	; 2b28 <_ump_osu_lock_trywait+0x290>
    .2a70: 	mov	r1, r5
    .2a74: 	ldr	r2, [r4, #16]
    .2a78: 	add	r0, pc, r3
    .2a7c: 	bl	10f8 <printf@plt>
    .2a80: 	mov	r0, #10
    .2a84: 	bl	1104 <putchar@plt>
    .2a88: 	bl	1110 <abort@plt>
    .2a8c: 	ldr	lr, [pc, #152]	; 2b2c <_ump_osu_lock_trywait+0x294>
    .2a90: 	ldr	r5, [pc, #152]	; 2b30 <_ump_osu_lock_trywait+0x298>
    .2a94: 	add	r0, pc, lr
    .2a98: 	bl	10ec <puts@plt>
    .2a9c: 	ldr	r1, [pc, #144]	; 2b34 <_ump_osu_lock_trywait+0x29c>
    .2aa0: 	add	r0, pc, r1
    .2aa4: 	bl	10f8 <printf@plt>
    .2aa8: 	ldr	r3, [pc, #136]	; 2b38 <_ump_osu_lock_trywait+0x2a0>
    .2aac: 	movw	r2, #430	; 0x1ae
    .2ab0: 	add	r1, pc, r5
    .2ab4: 	add	r0, pc, r3
    .2ab8: 	bl	10f8 <printf@plt>
    .2abc: 	ldr	r2, [r4, #16]
    .2ac0: 	ldr	r4, [pc, #116]	; 2b3c <_ump_osu_lock_trywait+0x2a4>
    .2ac4: 	mov	r1, #0
    .2ac8: 	add	r0, pc, r4
    .2acc: 	bl	10f8 <printf@plt>
    .2ad0: 	mov	r0, #10
    .2ad4: 	bl	1104 <putchar@plt>
    .2ad8: 	bl	1110 <abort@plt>
    .2adc: 	andeq	r0, r0, r8, lsl pc
    .2ae0: 	andeq	r1, r0, r0, lsl r2
    .2ae4: 	andeq	r0, r0, r8, asr #29
    .2ae8: 	andeq	r0, r0, ip, asr #30
    .2aec: 	strdeq	r1, [r0], -r0
    .2af0: 	andeq	r0, r0, r0, ror lr
    .2af4: 	andeq	r0, r0, r4, lsr #28
    .2af8: 	andeq	r0, r0, ip, lsr #29
    .2afc: 	andeq	r0, r0, r8, lsr #29
    .2b00: 	strdeq	r0, [r0], -r0	; <UNPREDICTABLE>
    .2b04: 	andeq	r0, r0, r8, lsr #28
    .2b08: 	andeq	r0, r0, r4, ror #28
    .2b0c: 	andeq	r0, r0, r0, ror #28
    .2b10: 	ldrdeq	r0, [r0], -r4
    .2b14: 	muleq	r0, r4, pc	; <UNPREDICTABLE>
    .2b18: 	ldrdeq	r0, [r0], -ip
    .2b1c: 	andeq	r0, r0, r8, lsl lr
    .2b20: 	andeq	r0, r0, r8, lsl lr
    .2b24: 	andeq	r0, r0, ip, lsl #27
    .2b28: 	ldrdeq	r1, [r0], -r4
    .2b2c: 	andeq	r0, r0, ip, lsl #27
    .2b30: 	andeq	r0, r0, r0, asr #26
    .2b34: 	andeq	r0, r0, r8, asr #27
    .2b38: 	andeq	r0, r0, r4, asr #27
    .2b3c: 	andeq	r1, r0, r4, lsl #1
    .
.globl _ump_osu_lock_signal
_ump_osu_lock_signal:
    .2b40: 	push	{r4, r5, r6, lr}
    .2b44: 	subs	r4, r0, #0
    .2b48: 	mov	r5, r1
    .2b4c: 	beq	2cc0 <_ump_osu_lock_signal+0x180>
    .2b50: 	cmp	r1, #0
    .2b54: 	bne	2c74 <_ump_osu_lock_signal+0x134>
    .2b58: 	ldr	r3, [r4]
    .2b5c: 	cmp	r3, #65536	; 0x10000
    .2b60: 	beq	2c30 <_ump_osu_lock_signal+0xf0>
    .2b64: 	cmp	r3, #131072	; 0x20000
    .2b68: 	beq	2b74 <_ump_osu_lock_signal+0x34>
    .2b6c: 	cmp	r3, #0
    .2b70: 	bne	2be4 <_ump_osu_lock_signal+0xa4>
    .2b74: 	ldr	r1, [r4, #16]
    .2b78: 	cmp	r1, #0
    .2b7c: 	bne	2da4 <_ump_osu_lock_signal+0x264>
    .2b80: 	add	r0, r4, #4
    .2b84: 	mvn	lr, #0
    .2b88: 	str	lr, [r4, #16]
    .2b8c: 	bl	1200 <pthread_mutex_unlock@plt>
    .2b90: 	subs	r4, r0, #0
    .2b94: 	popeq	{r4, r5, r6, pc}
    .2b98: 	ldr	r5, [pc, #596]	; 2df4 <_ump_osu_lock_signal+0x2b4>
    .2b9c: 	add	r0, pc, r5
    .2ba0: 	bl	10ec <puts@plt>
    .2ba4: 	ldr	r3, [pc, #588]	; 2df8 <_ump_osu_lock_signal+0x2b8>
    .2ba8: 	add	r0, pc, r3
    .2bac: 	bl	10f8 <printf@plt>
    .2bb0: 	ldr	r0, [pc, #580]	; 2dfc <_ump_osu_lock_signal+0x2bc>
    .2bb4: 	ldr	r1, [pc, #580]	; 2e00 <_ump_osu_lock_signal+0x2c0>
    .2bb8: 	mov	r2, #472	; 0x1d8
    .2bbc: 	add	r0, pc, r0
    .2bc0: 	add	r1, pc, r1
    .2bc4: 	bl	10f8 <printf@plt>
    .2bc8: 	mov	r1, r4
    .2bcc: 	ldr	r4, [pc, #560]	; 2e04 <_ump_osu_lock_signal+0x2c4>
    .2bd0: 	add	r0, pc, r4
    .2bd4: 	bl	10f8 <printf@plt>
    .2bd8: 	mov	r0, #10
    .2bdc: 	bl	1104 <putchar@plt>
    .2be0: 	bl	1110 <abort@plt>
    .2be4: 	ldr	lr, [pc, #540]	; 2e08 <_ump_osu_lock_signal+0x2c8>
    .2be8: 	add	r0, pc, lr
    .2bec: 	bl	10ec <puts@plt>
    .2bf0: 	ldr	r2, [pc, #532]	; 2e0c <_ump_osu_lock_signal+0x2cc>
    .2bf4: 	add	r0, pc, r2
    .2bf8: 	bl	10f8 <printf@plt>
    .2bfc: 	ldr	ip, [pc, #524]	; 2e10 <_ump_osu_lock_signal+0x2d0>
    .2c00: 	ldr	r3, [pc, #524]	; 2e14 <_ump_osu_lock_signal+0x2d4>
    .2c04: 	movw	r2, #499	; 0x1f3
    .2c08: 	add	r0, pc, ip
    .2c0c: 	add	r1, pc, r3
    .2c10: 	bl	10f8 <printf@plt>
    .2c14: 	ldr	r0, [pc, #508]	; 2e18 <_ump_osu_lock_signal+0x2d8>
    .2c18: 	ldr	r1, [r4]
    .2c1c: 	add	r0, pc, r0
    .2c20: 	bl	10f8 <printf@plt>
    .2c24: 	mov	r0, #10
    .2c28: 	pop	{r4, r5, r6, lr}
    .2c2c: 	b	1104 <putchar@plt>
    .2c30: 	add	r6, r4, #4
    .2c34: 	mov	r0, r6
    .2c38: 	bl	11f4 <pthread_mutex_lock@plt>
    .2c3c: 	ldr	r2, [r4, #12]
    .2c40: 	cmp	r2, #1
    .2c44: 	bne	2d08 <_ump_osu_lock_signal+0x1c8>
    .2c48: 	ldr	r3, [r4, #16]
    .2c4c: 	cmp	r3, #0
    .2c50: 	bne	2d54 <_ump_osu_lock_signal+0x214>
    .2c54: 	mvn	r1, #0
    .2c58: 	str	r3, [r4, #12]
    .2c5c: 	str	r1, [r4, #16]
    .2c60: 	add	r0, r4, #8
    .2c64: 	bl	123c <pthread_cond_signal@plt>
    .2c68: 	mov	r0, r6
    .2c6c: 	pop	{r4, r5, r6, lr}
    .2c70: 	b	1200 <pthread_mutex_unlock@plt>
    .2c74: 	ldr	lr, [pc, #416]	; 2e1c <_ump_osu_lock_signal+0x2dc>
    .2c78: 	ldr	r6, [pc, #416]	; 2e20 <_ump_osu_lock_signal+0x2e0>
    .2c7c: 	add	r0, pc, lr
    .2c80: 	bl	10ec <puts@plt>
    .2c84: 	ldr	r0, [pc, #408]	; 2e24 <_ump_osu_lock_signal+0x2e4>
    .2c88: 	add	r0, pc, r0
    .2c8c: 	bl	10f8 <printf@plt>
    .2c90: 	ldr	ip, [pc, #400]	; 2e28 <_ump_osu_lock_signal+0x2e8>
    .2c94: 	mov	r2, #452	; 0x1c4
    .2c98: 	add	r1, pc, r6
    .2c9c: 	add	r0, pc, ip
    .2ca0: 	bl	10f8 <printf@plt>
    .2ca4: 	mov	r1, r5
    .2ca8: 	ldr	r5, [pc, #380]	; 2e2c <_ump_osu_lock_signal+0x2ec>
    .2cac: 	add	r0, pc, r5
    .2cb0: 	bl	10f8 <printf@plt>
    .2cb4: 	mov	r0, #10
    .2cb8: 	bl	1104 <putchar@plt>
    .2cbc: 	bl	1110 <abort@plt>
    .2cc0: 	ldr	r4, [pc, #360]	; 2e30 <_ump_osu_lock_signal+0x2f0>
    .2cc4: 	add	r0, pc, r4
    .2cc8: 	bl	10ec <puts@plt>
    .2ccc: 	ldr	r2, [pc, #352]	; 2e34 <_ump_osu_lock_signal+0x2f4>
    .2cd0: 	add	r0, pc, r2
    .2cd4: 	bl	10f8 <printf@plt>
    .2cd8: 	ldr	r3, [pc, #344]	; 2e38 <_ump_osu_lock_signal+0x2f8>
    .2cdc: 	ldr	r1, [pc, #344]	; 2e3c <_ump_osu_lock_signal+0x2fc>
    .2ce0: 	movw	r2, #449	; 0x1c1
    .2ce4: 	add	r0, pc, r3
    .2ce8: 	add	r1, pc, r1
    .2cec: 	bl	10f8 <printf@plt>
    .2cf0: 	ldr	r0, [pc, #328]	; 2e40 <_ump_osu_lock_signal+0x300>
    .2cf4: 	add	r0, pc, r0
    .2cf8: 	bl	10f8 <printf@plt>
    .2cfc: 	mov	r0, #10
    .2d00: 	bl	1104 <putchar@plt>
    .2d04: 	bl	1110 <abort@plt>
    .2d08: 	ldr	lr, [pc, #308]	; 2e44 <_ump_osu_lock_signal+0x304>
    .2d0c: 	ldr	r6, [pc, #308]	; 2e48 <_ump_osu_lock_signal+0x308>
    .2d10: 	add	r0, pc, lr
    .2d14: 	bl	10ec <puts@plt>
    .2d18: 	ldr	r0, [pc, #300]	; 2e4c <_ump_osu_lock_signal+0x30c>
    .2d1c: 	add	r0, pc, r0
    .2d20: 	bl	10f8 <printf@plt>
    .2d24: 	ldr	ip, [pc, #292]	; 2e50 <_ump_osu_lock_signal+0x310>
    .2d28: 	ldr	r1, [pc, #292]	; 2e54 <_ump_osu_lock_signal+0x314>
    .2d2c: 	movw	r2, #482	; 0x1e2
    .2d30: 	add	r0, pc, r1
    .2d34: 	add	r1, pc, ip
    .2d38: 	bl	10f8 <printf@plt>
    .2d3c: 	mov	r1, r4
    .2d40: 	add	r0, pc, r6
    .2d44: 	bl	10f8 <printf@plt>
    .2d48: 	mov	r0, #10
    .2d4c: 	bl	1104 <putchar@plt>
    .2d50: 	bl	1110 <abort@plt>
    .2d54: 	ldr	ip, [pc, #252]	; 2e58 <_ump_osu_lock_signal+0x318>
    .2d58: 	ldr	r6, [pc, #252]	; 2e5c <_ump_osu_lock_signal+0x31c>
    .2d5c: 	add	r0, pc, ip
    .2d60: 	bl	10ec <puts@plt>
    .2d64: 	ldr	r2, [pc, #244]	; 2e60 <_ump_osu_lock_signal+0x320>
    .2d68: 	add	r0, pc, r2
    .2d6c: 	bl	10f8 <printf@plt>
    .2d70: 	ldr	r3, [pc, #236]	; 2e64 <_ump_osu_lock_signal+0x324>
    .2d74: 	movw	r2, #486	; 0x1e6
    .2d78: 	add	r0, pc, r6
    .2d7c: 	add	r1, pc, r3
    .2d80: 	bl	10f8 <printf@plt>
    .2d84: 	ldr	r1, [r4, #16]
    .2d88: 	ldr	r4, [pc, #216]	; 2e68 <_ump_osu_lock_signal+0x328>
    .2d8c: 	mov	r2, r5
    .2d90: 	add	r0, pc, r4
    .2d94: 	bl	10f8 <printf@plt>
    .2d98: 	mov	r0, #10
    .2d9c: 	bl	1104 <putchar@plt>
    .2da0: 	bl	1110 <abort@plt>
    .2da4: 	ldr	ip, [pc, #192]	; 2e6c <_ump_osu_lock_signal+0x32c>
    .2da8: 	ldr	r6, [pc, #192]	; 2e70 <_ump_osu_lock_signal+0x330>
    .2dac: 	add	r0, pc, ip
    .2db0: 	ldr	r5, [pc, #188]	; 2e74 <_ump_osu_lock_signal+0x334>
    .2db4: 	bl	10ec <puts@plt>
    .2db8: 	ldr	r2, [pc, #184]	; 2e78 <_ump_osu_lock_signal+0x338>
    .2dbc: 	add	r0, pc, r2
    .2dc0: 	bl	10f8 <printf@plt>
    .2dc4: 	movw	r2, #465	; 0x1d1
    .2dc8: 	add	r1, pc, r5
    .2dcc: 	add	r0, pc, r6
    .2dd0: 	bl	10f8 <printf@plt>
    .2dd4: 	ldr	r3, [pc, #160]	; 2e7c <_ump_osu_lock_signal+0x33c>
    .2dd8: 	ldr	r1, [r4, #16]
    .2ddc: 	mov	r2, #0
    .2de0: 	add	r0, pc, r3
    .2de4: 	bl	10f8 <printf@plt>
    .2de8: 	mov	r0, #10
    .2dec: 	bl	1104 <putchar@plt>
    .2df0: 	bl	1110 <abort@plt>
    .2df4: 	andeq	r0, r0, r4, lsl #25
    .2df8: 	andeq	r0, r0, r0, asr #25
    .2dfc: 			; <UNDEFINED> instruction: 0x00000cbc
    .2e00: 	andeq	r0, r0, r8, asr #24
    .2e04: 	andeq	r0, r0, r0, lsr #30
    .2e08: 	andeq	r0, r0, r8, lsr ip
    .2e0c: 	andeq	r0, r0, r0, lsr pc
    .2e10: 	andeq	r0, r0, r0, ror ip
    .2e14: 	strdeq	r0, [r0], -ip
    .2e18: 	andeq	r0, r0, r0, lsl pc
    .2e1c: 	andeq	r0, r0, r4, lsr #23
    .2e20: 	andeq	r0, r0, r0, ror fp
    .2e24: 	andeq	r0, r0, r0, ror #23
    .2e28: 	ldrdeq	r0, [r0], -ip
    .2e2c: 	andeq	r0, r0, r4, lsr #26
    .2e30: 	andeq	r0, r0, ip, asr fp
    .2e34: 	muleq	r0, r8, fp
    .2e38: 	muleq	r0, r4, fp
    .2e3c: 	andeq	r0, r0, r0, lsr #22
    .2e40: 	andeq	r0, r0, r8, asr #25
    .2e44: 	andeq	r0, r0, r0, lsl fp
    .2e48: 	andeq	r0, r0, r0, lsl #29
    .2e4c: 	andeq	r0, r0, ip, asr #22
    .2e50: 	ldrdeq	r0, [r0], -r4
    .2e54: 	andeq	r0, r0, r8, asr #22
    .2e58: 	andeq	r0, r0, r4, asr #21
    .2e5c: 	andeq	r0, r0, r0, lsl #22
    .2e60: 	andeq	r0, r0, r0, lsl #22
    .2e64: 	andeq	r0, r0, ip, lsl #21
    .2e68: 	andeq	r0, r0, r4, ror #28
    .2e6c: 	andeq	r0, r0, r4, ror sl
    .2e70: 	andeq	r0, r0, ip, lsr #21
    .2e74: 	andeq	r0, r0, r0, asr #20
    .2e78: 	andeq	r0, r0, ip, lsr #21
    .2e7c: 	muleq	r0, ip, sp
    .
.globl _ump_osu_lock_term
_ump_osu_lock_term:
    .2e80: 	push	{r3, r4, r5, lr}
    .2e84: 	subs	r4, r0, #0
    .2e88: 	beq	2edc <_ump_osu_lock_term+0x5c>
    .2e8c: 	ldr	r5, [r4, #16]
    .2e90: 	cmn	r5, #1
    .2e94: 	bne	2f70 <_ump_osu_lock_term+0xf0>
    .2e98: 	add	r0, r4, #4
    .2e9c: 	bl	11e8 <pthread_mutex_destroy@plt>
    .2ea0: 	subs	r5, r0, #0
    .2ea4: 	bne	2f24 <_ump_osu_lock_term+0xa4>
    .2ea8: 	ldr	r3, [r4]
    .2eac: 	tst	r3, #65536	; 0x10000
    .2eb0: 	beq	2ed0 <_ump_osu_lock_term+0x50>
    .2eb4: 	ldr	r5, [r4, #12]
    .2eb8: 	cmp	r5, #0
    .2ebc: 	bne	3004 <_ump_osu_lock_term+0x184>
    .2ec0: 	add	r0, r4, #8
    .2ec4: 	bl	1248 <pthread_cond_destroy@plt>
    .2ec8: 	subs	r5, r0, #0
    .2ecc: 	bne	2fb8 <_ump_osu_lock_term+0x138>
    .2ed0: 	mov	r0, r4
    .2ed4: 	pop	{r3, r4, r5, lr}
    .2ed8: 	b	1ebc <_ump_osu_free>
    .2edc: 	ldr	r4, [pc, #364]	; 3050 <_ump_osu_lock_term+0x1d0>
    .2ee0: 	add	r0, pc, r4
    .2ee4: 	bl	10ec <puts@plt>
    .2ee8: 	ldr	r2, [pc, #356]	; 3054 <_ump_osu_lock_term+0x1d4>
    .2eec: 	add	r0, pc, r2
    .2ef0: 	bl	10f8 <printf@plt>
    .2ef4: 	ldr	r3, [pc, #348]	; 3058 <_ump_osu_lock_term+0x1d8>
    .2ef8: 	ldr	r1, [pc, #348]	; 305c <_ump_osu_lock_term+0x1dc>
    .2efc: 	movw	r2, #507	; 0x1fb
    .2f00: 	add	r0, pc, r3
    .2f04: 	add	r1, pc, r1
    .2f08: 	bl	10f8 <printf@plt>
    .2f0c: 	ldr	r0, [pc, #332]	; 3060 <_ump_osu_lock_term+0x1e0>
    .2f10: 	add	r0, pc, r0
    .2f14: 	bl	10f8 <printf@plt>
    .2f18: 	mov	r0, #10
    .2f1c: 	bl	1104 <putchar@plt>
    .2f20: 	bl	1110 <abort@plt>
    .2f24: 	ldr	r0, [pc, #312]	; 3064 <_ump_osu_lock_term+0x1e4>
    .2f28: 	ldr	r4, [pc, #312]	; 3068 <_ump_osu_lock_term+0x1e8>
    .2f2c: 	add	r0, pc, r0
    .2f30: 	bl	10ec <puts@plt>
    .2f34: 	ldr	r1, [pc, #304]	; 306c <_ump_osu_lock_term+0x1ec>
    .2f38: 	add	r0, pc, r1
    .2f3c: 	bl	10f8 <printf@plt>
    .2f40: 	ldr	ip, [pc, #296]	; 3070 <_ump_osu_lock_term+0x1f0>
    .2f44: 	mov	r2, #516	; 0x204
    .2f48: 	add	r1, pc, r4
    .2f4c: 	add	r0, pc, ip
    .2f50: 	bl	10f8 <printf@plt>
    .2f54: 	ldr	r2, [pc, #280]	; 3074 <_ump_osu_lock_term+0x1f4>
    .2f58: 	mov	r1, r5
    .2f5c: 	add	r0, pc, r2
    .2f60: 	bl	10f8 <printf@plt>
    .2f64: 	mov	r0, #10
    .2f68: 	bl	1104 <putchar@plt>
    .2f6c: 	bl	1110 <abort@plt>
    .2f70: 	ldr	lr, [pc, #256]	; 3078 <_ump_osu_lock_term+0x1f8>
    .2f74: 	add	r0, pc, lr
    .2f78: 	bl	10ec <puts@plt>
    .2f7c: 	ldr	r3, [pc, #248]	; 307c <_ump_osu_lock_term+0x1fc>
    .2f80: 	add	r0, pc, r3
    .2f84: 	bl	10f8 <printf@plt>
    .2f88: 	ldr	r0, [pc, #240]	; 3080 <_ump_osu_lock_term+0x200>
    .2f8c: 	ldr	r1, [pc, #240]	; 3084 <_ump_osu_lock_term+0x204>
    .2f90: 	mov	r2, #512	; 0x200
    .2f94: 	add	r0, pc, r0
    .2f98: 	add	r1, pc, r1
    .2f9c: 	bl	10f8 <printf@plt>
    .2fa0: 	ldr	ip, [pc, #224]	; 3088 <_ump_osu_lock_term+0x208>
    .2fa4: 	add	r0, pc, ip
    .2fa8: 	bl	10ec <puts@plt>
    .2fac: 	mov	r0, #10
    .2fb0: 	bl	1104 <putchar@plt>
    .2fb4: 	bl	1110 <abort@plt>
    .2fb8: 	ldr	r1, [pc, #204]	; 308c <_ump_osu_lock_term+0x20c>
    .2fbc: 	ldr	r4, [pc, #204]	; 3090 <_ump_osu_lock_term+0x210>
    .2fc0: 	add	r0, pc, r1
    .2fc4: 	bl	10ec <puts@plt>
    .2fc8: 	ldr	r2, [pc, #196]	; 3094 <_ump_osu_lock_term+0x214>
    .2fcc: 	add	r0, pc, r2
    .2fd0: 	bl	10f8 <printf@plt>
    .2fd4: 	ldr	ip, [pc, #188]	; 3098 <_ump_osu_lock_term+0x218>
    .2fd8: 	ldr	r3, [pc, #188]	; 309c <_ump_osu_lock_term+0x21c>
    .2fdc: 	mov	r2, #524	; 0x20c
    .2fe0: 	add	r0, pc, ip
    .2fe4: 	add	r1, pc, r3
    .2fe8: 	bl	10f8 <printf@plt>
    .2fec: 	mov	r1, r5
    .2ff0: 	add	r0, pc, r4
    .2ff4: 	bl	10f8 <printf@plt>
    .2ff8: 	mov	r0, #10
    .2ffc: 	bl	1104 <putchar@plt>
    .3000: 	bl	1110 <abort@plt>
    .3004: 	ldr	lr, [pc, #148]	; 30a0 <_ump_osu_lock_term+0x220>
    .3008: 	add	r0, pc, lr
    .300c: 	bl	10ec <puts@plt>
    .3010: 	ldr	r0, [pc, #140]	; 30a4 <_ump_osu_lock_term+0x224>
    .3014: 	add	r0, pc, r0
    .3018: 	bl	10f8 <printf@plt>
    .301c: 	ldr	ip, [pc, #132]	; 30a8 <_ump_osu_lock_term+0x228>
    .3020: 	ldr	r1, [pc, #132]	; 30ac <_ump_osu_lock_term+0x22c>
    .3024: 	movw	r2, #521	; 0x209
    .3028: 	add	r0, pc, r1
    .302c: 	add	r1, pc, ip
    .3030: 	bl	10f8 <printf@plt>
    .3034: 	ldr	r2, [pc, #116]	; 30b0 <_ump_osu_lock_term+0x230>
    .3038: 	mov	r1, r4
    .303c: 	add	r0, pc, r2
    .3040: 	bl	10f8 <printf@plt>
    .3044: 	mov	r0, #10
    .3048: 	bl	1104 <putchar@plt>
    .304c: 	bl	1110 <abort@plt>
    .3050: 	andeq	r0, r0, r0, asr #18
    .3054: 	andeq	r0, r0, ip, ror r9
    .3058: 	andeq	r0, r0, r8, ror r9
    .305c: 	andeq	r0, r0, r4, ror #28
    .3060: 	andeq	r0, r0, ip, lsr #21
    .3064: 	strdeq	r0, [r0], -r4
    .3068: 	andeq	r0, r0, r0, lsr #28
    .306c: 	andeq	r0, r0, r0, lsr r9
    .3070: 	andeq	r0, r0, ip, lsr #18
    .3074: 	strdeq	r0, [r0], -r0	; <UNPREDICTABLE>
    .3078: 	andeq	r0, r0, ip, lsr #17
    .307c: 	andeq	r0, r0, r8, ror #17
    .3080: 	andeq	r0, r0, r4, ror #17
    .3084: 	ldrdeq	r0, [r0], -r0	; <UNPREDICTABLE>
    .3088: 	andeq	r0, r0, ip, lsl #25
    .308c: 	andeq	r0, r0, r0, ror #16
    .3090: 	ldrdeq	r0, [r0], -r8
    .3094: 	muleq	r0, ip, r8
    .3098: 	muleq	r0, r8, r8
    .309c: 	andeq	r0, r0, r4, lsl #27
    .30a0: 	andeq	r0, r0, r8, lsl r8
    .30a4: 	andeq	r0, r0, r4, asr r8
    .30a8: 	andeq	r0, r0, ip, lsr sp
    .30ac: 	andeq	r0, r0, r0, asr r8
    .30b0: 	andeq	r0, r0, r4, ror #24
    .
.globl _ump_osu_lock_static
_ump_osu_lock_static:
    .30b4: 	cmp	r0, #3
    .30b8: 	push	{r4, lr}
    .30bc: 	mov	r4, r0
    .30c0: 	bhi	30d8 <_ump_osu_lock_static+0x24>
    .30c4: 	ldr	r1, [pc, #92]	; 3128 <_ump_osu_lock_static+0x74>
    .30c8: 	add	r4, r0, r0, lsl #2
    .30cc: 	add	r0, pc, r1
    .30d0: 	add	r0, r0, r4, lsl #2
    .30d4: 	pop	{r4, pc}
    .30d8: 	ldr	ip, [pc, #76]	; 312c <_ump_osu_lock_static+0x78>
    .30dc: 	add	r0, pc, ip
    .30e0: 	bl	10ec <puts@plt>
    .30e4: 	ldr	r2, [pc, #68]	; 3130 <_ump_osu_lock_static+0x7c>
    .30e8: 	add	r0, pc, r2
    .30ec: 	bl	10f8 <printf@plt>
    .30f0: 	ldr	r3, [pc, #60]	; 3134 <_ump_osu_lock_static+0x80>
    .30f4: 	ldr	r1, [pc, #60]	; 3138 <_ump_osu_lock_static+0x84>
    .30f8: 	movw	r2, #535	; 0x217
    .30fc: 	add	r0, pc, r3
    .3100: 	add	r1, pc, r1
    .3104: 	bl	10f8 <printf@plt>
    .3108: 	ldr	r0, [pc, #44]	; 313c <_ump_osu_lock_static+0x88>
    .310c: 	mov	r1, r4
    .3110: 	mov	r2, #4
    .3114: 	add	r0, pc, r0
    .3118: 	bl	10f8 <printf@plt>
    .311c: 	mov	r0, #10
    .3120: 	bl	1104 <putchar@plt>
    .3124: 	bl	1110 <abort@plt>
    .3128: 	andeq	r1, r0, ip, lsr #30
    .312c: 	andeq	r0, r0, r4, asr #14
    .3130: 	andeq	r0, r0, r0, lsl #15
    .3134: 	andeq	r0, r0, ip, ror r7
    .3138: 	muleq	r0, r4, ip
    .313c: 	andeq	r0, r0, r4, lsl ip
    .
.globl __on_dlclose
__on_dlclose:
    .3140: 	add	r0, pc, #4
    .3144: 	ldr	r0, [r0]
    .3148: 	b	1254 <__cxa_finalize@plt>
    .314c: 	andeq	r5, r0, r0, rrx
