/*
 * FUN_00402080 at 00402080
 * undefined FUN_00402080(void)
 * Address ranges: 00402080-004020cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402080(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&DAT_00503ef8 + param_1 * 0x11c);
  uVar1 = *(undefined4 *)(iVar3 * 0xd0 + 0x24 + DAT_0067ee20);
  iVar2 = FUN_00401cf0(param_1);
  if (iVar2 == 0) {
    iVar3 = FUN_0040a120(iVar3,uVar1);
    if (iVar3 == 1) {
      return 1;
    }
  }
  return 0;
}

