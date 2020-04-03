#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/calclock.h>

extern int enabled;
extern unsigned long long a_t[NUMCORE], a_c[NUMCORE];
extern unsigned long long b_t[NUMCORE], b_c[NUMCORE];
extern unsigned long long c_t[NUMCORE], c_c[NUMCORE];
extern unsigned long long d_t[NUMCORE], d_c[NUMCORE];
extern unsigned long long e_t[NUMCORE], e_c[NUMCORE];
extern unsigned long long f_t[NUMCORE], f_c[NUMCORE];
extern unsigned long long g_t[NUMCORE], g_c[NUMCORE];
extern unsigned long long h_t[NUMCORE], h_c[NUMCORE];
extern unsigned long long i_t[NUMCORE], i_c[NUMCORE];
extern unsigned long long j_t[NUMCORE], j_c[NUMCORE];
extern unsigned long long k_t[NUMCORE], k_c[NUMCORE];
extern unsigned long long l_t[NUMCORE], l_c[NUMCORE];
extern unsigned long long m_t[NUMCORE], m_c[NUMCORE];

static int __init init_mymodule(void)
{
	enabled = 1;
	int i;
	for (i=0; i<NUMCORE; i++){
		a_t[i] = 0, a_c[i] = 0;
		b_t[i] = 0, b_c[i] = 0;
	  c_t[i] = 0, c_c[i] = 0;
		d_t[i] = 0, d_c[i] = 0;
		e_t[i] = 0, e_c[i] = 0;
		f_t[i] = 0, f_c[i] = 0;
		g_t[i] = 0, g_c[i] = 0;
		h_t[i] = 0, h_c[i] = 0;
		i_t[i] = 0, i_c[i] = 0;
		j_t[i] = 0, j_c[i] = 0;
		k_t[i] = 0, k_c[i] = 0;
		l_t[i] = 0, l_c[i] = 0;
		m_t[i] = 0, m_c[i] = 0;
	}
	printk("=====IO profiling=====\n");
	return 0;
}
static int __exit exit_mymodule(void)
{
	enabled = 0;
	unsigned long long a_time = 0, a_count = 0;
	unsigned long long b_time = 0, b_count = 0;
	unsigned long long c_time = 0, c_count = 0;
	unsigned long long d_time = 0, d_count = 0;
  unsigned long long e_time = 0, e_count = 0;
	unsigned long long f_time = 0, f_count = 0;
	unsigned long long g_time = 0, g_count = 0;
	unsigned long long h_time = 0, h_count = 0;
	unsigned long long i_time = 0, i_count = 0;
	unsigned long long j_time = 0, j_count = 0;
	unsigned long long k_time = 0, k_count = 0;
	unsigned long long l_time = 0, l_count = 0;
	unsigned long long m_time = 0, m_count = 0;

	int i;
	for (i=0; i<NUMCORE; i++){
		a_time += a_t[i];
		a_count += a_c[i];
		b_time += b_t[i];
		b_count += b_c[i];
	  c_time += c_t[i];
		c_count += c_c[i];
		d_time += d_t[i];
		d_count += d_c[i];
		e_time += e_t[i];
		e_count += e_c[i];
		f_time += f_t[i];
		f_count += f_c[i];
		g_time += g_t[i];
		g_count += g_c[i];
		h_time += h_t[i];
		h_count += h_c[i];
		i_time += i_t[i];
		i_count += i_c[i];
		j_time += j_t[i];
		j_count += j_c[i];
		k_time += k_t[i];
		k_count += k_c[i];
		l_time += l_t[i];
		l_count += l_c[i];
		m_time += m_t[i];
		m_count += m_c[i];
	}
//	printk("a_time : %llu, a_count : %llu\n", a_time, a_count);
//	printk("b_time : %llu, b_count : %llu\n", b_time, b_count);
//	printk("c_time : %llu, c_count : %llu\n", c_time, c_count);
//	printk("d_time : %llu, d_count : %llu\n", d_time, d_count);
//	printk("release_pages------ : %llu, e_count : %llu\n", e_time, e_count);
//	printk("f_time : %llu, f_count : %llu\n", f_time, f_count);
//	printk("add_pagevec_release : %llu, g_count : %llu\n", g_time, g_count);
//	printk("h_time : %llu, h_count : %llu\n", h_time, h_count);
//	printk("i_time : %llu, i_count : %llu\n", i_time, i_count);
//	printk("j_time : %llu, j_count : %llu\n", j_time, j_count);
//	printk("k_time : %llu, k_count : %llu\n", k_time, k_count);
//	printk("l_time : %llu, l_count : %llu\n", l_time, l_count);
	printk("add_pagevec:%llu", m_time); //, m_count : %llu\n", m_time, m_count);
	
	return 0;
}
module_init(init_mymodule);
module_exit(exit_mymodule);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jiwoo Bang");
MODULE_DESCRIPTION("For measuring the function time");
