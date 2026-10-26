/*
 * FUN_0040bd58 at 0040bd58
 * undefined __register FUN_0040bd58(void)
 * Address ranges: 0040bd58-0040bde1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040bd58(void)

{
  DWORD DVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffd0;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_18;
  DWORD local_14;
  undefined1 local_10;
  int local_c;
  undefined1 local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_18 = 0;
  puStack_24 = &LAB_0040bde2;
  puStack_28 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_28;
  DVar1 = GetLastError();
  if (DVar1 == 0) {
    piVar2 = FUN_0040ad20((int *)&DAT_00407a88,'\x01',(undefined4 *)PTR_PTR_0047c700);
  }
  else {
    local_10 = 0;
    local_14 = DVar1;
    FUN_0040a478(DVar1,&local_18);
    local_c = local_18;
    local_8 = 0xb;
    in_stack_ffffffd0 = 1;
    piVar2 = (int *)FUN_0040ad5c((int)&DAT_00407a88,'\x01',(undefined4 *)PTR_PTR_0047c62c,1,
                                 &local_14);
  }
  piVar2[3] = DVar1;
  FUN_00403604(piVar2);
  *in_FS_OFFSET = in_stack_ffffffd0;
  puStack_28 = &LAB_0040bde9;
  FUN_00403b50(&local_18);
  return;
}

