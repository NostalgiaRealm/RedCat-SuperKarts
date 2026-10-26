/*
 * FUN_004b9af0 at 004b9af0
 * undefined FUN_004b9af0(void)
 * Address ranges: 004b9af0-004b9ba7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b9af0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_304 [4];
  undefined1 local_300 [256];
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  FUN_004c00b6(param_2,local_304,local_100,local_200,local_300);
  FUN_004c0025(param_1,&DAT_005437b0,&DAT_005437b0,local_200,local_300);
  FUN_004afce0(s_path__s_00501c60,param_1);
  iVar1 = FUN_004bf445(param_1,&DAT_00501c5c);
  if (iVar1 == 0) {
    FUN_004c0025(param_1,&DAT_006ab950,DAT_006ab94c,local_200,local_300);
    FUN_004afce0(s_failed_goto_path__s_00501c44,param_1);
    return param_1;
  }
  FUN_004bf2c5(iVar1);
  return param_1;
}

