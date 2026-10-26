/*
 * FUN_004964e0 at 004964e0
 * undefined FUN_004964e0(void)
 * Address ranges: 004964e0-0049660f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004964e0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  void *pvVar1;
  
  pvVar1 = operator_new(param_4 << 7);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  *(void **)(param_1 + 0x5a) = pvVar1;
  pvVar1 = operator_new(param_3 << 7);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  *(void **)(param_1 + 0x7a) = pvVar1;
  pvVar1 = operator_new(param_2 << 7);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  *(void **)(param_1 + 0x6a) = pvVar1;
  pvVar1 = operator_new(param_5 << 7);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  *(void **)(param_1 + 0x8a) = pvVar1;
  pvVar1 = operator_new(param_4 * 0x18);
  *(void **)(param_1 + 0x5e) = pvVar1;
  pvVar1 = operator_new(param_5 * 0xc);
  *(void **)(param_1 + 0x8e) = pvVar1;
  pvVar1 = operator_new(param_3 * 0xc);
  *(void **)(param_1 + 0x7e) = pvVar1;
  pvVar1 = operator_new(param_2 * 0xc);
  *(void **)(param_1 + 0x6e) = pvVar1;
  *(undefined4 *)(param_1 + 0x92) = 0;
  *(undefined4 *)(param_1 + 0x82) = 0;
  *(undefined4 *)(param_1 + 0x62) = 0;
  *(undefined4 *)(param_1 + 0x72) = 0;
  *(undefined4 *)(param_1 + 0x96) = 0;
  *(undefined4 *)(param_1 + 0x86) = 0;
  *(undefined4 *)(param_1 + 0x66) = 0;
  *(undefined4 *)(param_1 + 0x76) = 0;
  DAT_00680b70 = param_1;
  return;
}

