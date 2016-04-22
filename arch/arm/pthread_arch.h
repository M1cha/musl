static inline pthread_t __pthread_self()
{
	char *p;
	__syscall(0xf0010, p);  // get_tls
	return (void *)(p+8-sizeof(struct pthread));
}

#define TLS_ABOVE_TP
#define TP_ADJ(p) ((char *)(p) + sizeof(struct pthread) - 8)

#define MC_PC arm_pc
