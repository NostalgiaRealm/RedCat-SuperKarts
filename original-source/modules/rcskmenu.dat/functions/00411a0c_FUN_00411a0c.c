/*
 * FUN_00411a0c at 00411a0c
 * undefined __register FUN_00411a0c(int param_1, int * param_2)
 * Address ranges: 00411a0c-00411a5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411a0c(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_1c;
  undefined1 *puStackY_18;
  
  puStackY_18 = (undefined1 *)0x411a28;
  piVar1 = FUN_00411eec((int *)&PTR_FUN_0040e870,'\x01',param_1,0x1000);
  puStackY_18 = &LAB_00411a5c;
  uStackY_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_1c;
  FUN_00413c68(piVar1,param_2);
  *in_FS_OFFSET = uStackY_1c;
  puStackY_18 = (undefined1 *)0x411a5b;
  FUN_00402eac(piVar1);
  return;
}

