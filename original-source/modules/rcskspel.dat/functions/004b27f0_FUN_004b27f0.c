/*
 * FUN_004b27f0 at 004b27f0
 * undefined FUN_004b27f0(void)
 * Address ranges: 004b27f0-004b2867
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b27f0(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined1 local_80 [4];
  short local_7c;
  short local_7a;
  short local_78;
  short local_76;
  
  iVar1 = FUN_004b96d0(param_1);
  if (iVar1 == 0) {
    return 1000;
  }
  FUN_004bf930(local_80,0x80,1,iVar1);
  *param_3 = ((int)local_76 - (int)local_7a) + 1;
  *param_2 = ((int)local_78 - (int)local_7c) + 1;
  FUN_004b9840(iVar1);
  return 0;
}

