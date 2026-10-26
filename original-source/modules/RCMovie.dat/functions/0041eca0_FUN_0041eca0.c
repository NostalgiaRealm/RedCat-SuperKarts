/*
 * FUN_0041eca0 at 0041eca0
 * undefined __thiscall FUN_0041eca0(void * this, int * param_1)
 * Address ranges: 0041eca0-0041ecb4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0041eca0(void *this,int *param_1)

{
  *(int **)((int)this + 5) = param_1;
  (**(code **)(*param_1 + 0xc))((int)this + 0x21);
  return;
}

