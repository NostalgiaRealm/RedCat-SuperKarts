/*
 * FUN_00425b11 at 00425b11
 * undefined * __stdcall FUN_00425b11(void)
 * Address ranges: 00425b11-00425b74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00425b11(void)

{
  undefined4 in_stack_ffffffd8;
  undefined2 uVar1;
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;
  
  uVar1 = (undefined2)((uint)in_stack_ffffffd8 >> 0x10);
  FUN_00425b75(&local_10,(uint *)&stack0x00000004);
  _DAT_0043e568 = FUN_00426c71(local_10,uStack_c,CONCAT22(uVar1,uStack_8),0x11,0,&DAT_0043e540);
  _DAT_0043e560 = (int)DAT_0043e542;
  _DAT_0043e564 = (int)DAT_0043e540;
  _DAT_0043e56c = &DAT_0043e544;
  return &DAT_0043e560;
}

