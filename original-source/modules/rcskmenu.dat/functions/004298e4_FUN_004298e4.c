/*
 * FUN_004298e4 at 004298e4
 * undefined __register FUN_004298e4(int * param_1)
 * Address ranges: 004298e4-00429954
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004298e4(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffd4;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  byte *local_10;
  int local_c;
  undefined1 local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_10 = (byte *)0x0;
  puStack_20 = &LAB_00429955;
  puStack_24 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_24;
  piVar1 = FUN_004298bc(param_1);
  if (piVar1 == (int *)0x0) {
    local_c = param_1[2];
    local_8 = 0xb;
    piVar1 = &local_c;
    in_stack_ffffffd4 = 0;
    FUN_00405438((undefined4 *)PTR_PTR_0047c8a8,(int *)&local_10);
    uVar2 = FUN_0040aca0((int)&DAT_0040de0c,'\x01',local_10,in_stack_ffffffd4,piVar1);
    FUN_00403604(uVar2);
  }
  *in_FS_OFFSET = in_stack_ffffffd4;
  puStack_24 = &LAB_0042995c;
  FUN_00403b50((int *)&local_10);
  return;
}

