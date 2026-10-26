/*
 * FUN_00412fa4 at 00412fa4
 * undefined __register FUN_00412fa4(int * param_1, int * param_2, uint param_3)
 * Address ranges: 00412fa4-00412ffe;00413006-00413013
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412fa4(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  if (param_1[0xc] == 0) {
    puStack_10 = (undefined1 *)0x412fc3;
    iVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
    param_1[0xc] = iVar1;
    puStack_14 = &LAB_00412fff;
    uStack_18 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_18;
    puStack_10 = &stack0xfffffffc;
    FUN_00413014(param_1,param_2,extraout_ECX);
    FUN_00412778(param_1);
    *in_FS_OFFSET = uStack_18;
    puStack_10 = (undefined1 *)0x413010;
    puStack_14 = (undefined1 *)0x412ffe;
    FUN_004128bc((int)param_1);
    return;
  }
  puStack_10 = (undefined1 *)0x413010;
  FUN_00413014(param_1,param_2,param_3);
  return;
}

