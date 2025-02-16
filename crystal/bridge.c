// crystal needs to init gc
extern void _crystal();
extern void GC_init();
extern void __crystal_main(int, int**);
void crystal() {
    GC_init();
    __crystal_main(0, (int **)0);
    _crystal();
}