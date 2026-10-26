/*
 * FUN_004521b4 at 004521b4
 * undefined FUN_004521b4(void)
 * Address ranges: 004521b4-0045225e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004521b4(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 *puStack_20;
  undefined4 *puStack_1c;
  short asStack_16 [7];
  int *piStack_8;
  
  puStack_2c = &stack0xfffffffc;
  puStack_20 = (undefined4 *)0x0;
  puStack_1c = (undefined4 *)0x0;
  puStack_30 = &LAB_0045225f;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  piStack_8 = param_2;
  iVar1 = (**(code **)(*param_2 + 4))(param_2,asStack_16,0xe);
  if (iVar1 != 0) {
    if (iVar1 != 0xe) {
      FUN_00405438((undefined4 *)PTR_PTR_0047c860,(int *)&puStack_1c);
      piVar2 = FUN_0040ac64((int *)&DAT_00415bf4,'\x01',puStack_1c);
      FUN_00403604(piVar2);
    }
    if (asStack_16[0] != 0x4d42) {
      FUN_00405438((undefined4 *)PTR_PTR_0047c860,(int *)&puStack_20);
      piVar2 = FUN_0040ac64((int *)&DAT_00415bf4,'\x01',puStack_20);
      FUN_00403604(piVar2);
    }
    (**(code **)(*param_1 + 0x30))(param_1,piStack_8);
  }
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_00452266;
  puStack_30 = (undefined1 *)0x45225e;
  FUN_00403b74((int *)&puStack_20,2);
  return;
}

