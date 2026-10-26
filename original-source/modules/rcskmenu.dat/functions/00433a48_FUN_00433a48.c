/*
 * FUN_00433a48 at 00433a48
 * undefined __register FUN_00433a48(int * param_1)
 * Address ranges: 00433a48-00433ad6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433a48(int *param_1)

{
  HIMAGELIST p_Var1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined4 *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_1c = &LAB_00433ad7;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  p_Var1 = ImageList_Create(param_1[10],param_1[9],
                            *(uint *)(&DAT_0047b7ec + (uint)*(byte *)((int)param_1 + 0x35) * 4) |
                            0xfe,param_1[0xb],param_1[0xb]);
  param_1[0xc] = (int)p_Var1;
  if (p_Var1 == (HIMAGELIST)0x0) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c880,(int *)&local_8);
    piVar2 = FUN_0040ac64((int *)&DAT_0040de0c,'\x01',local_8);
    FUN_00403604(piVar2);
  }
  if (param_1[0xe] != 0x1fffffff) {
    FUN_00433c6c(param_1,param_1[0xe]);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00433ade;
  puStack_1c = (undefined1 *)0x433ad6;
  FUN_00403b50((int *)&local_8);
  return;
}

