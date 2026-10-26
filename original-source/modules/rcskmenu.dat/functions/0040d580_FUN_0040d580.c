/*
 * FUN_0040d580 at 0040d580
 * undefined __register FUN_0040d580(int * param_1, int param_2, LPCSTR param_3)
 * Address ranges: 0040d580-0040d5c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d580(int *param_1,int param_2,LPCSTR param_3)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  OLECHAR *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (OLECHAR *)0x0;
  puStack_1c = &LAB_0040d5c8;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  FUN_00404288((BSTR)&local_8,param_3);
  FUN_0040d540(param_1,param_2,local_8);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0040d5cf;
  puStack_1c = (undefined1 *)0x40d5c7;
  FUN_00404180(&local_8);
  return;
}

