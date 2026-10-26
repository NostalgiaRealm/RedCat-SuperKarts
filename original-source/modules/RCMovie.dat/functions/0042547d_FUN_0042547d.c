/*
 * FUN_0042547d at 0042547d
 * uint __thiscall FUN_0042547d(void * this, uint param_1, uint param_2)
 * Address ranges: 0042547d-004254b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_0042547d(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_004254c8(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_0042555a(uVar1);
  return uVar1;
}

