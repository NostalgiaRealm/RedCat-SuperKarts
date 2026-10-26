/*
 * FUN_0045c910 at 0045c910
 * undefined __register FUN_0045c910(int param_1, int * param_2)
 * Address ranges: 0045c910-0045ca4d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c910(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  float10 in_ST0;
  float10 in_ST1;
  byte *pbStack_58;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  int local_2c;
  int local_28;
  double local_24;
  double local_1c;
  byte *local_10;
  byte *local_c;
  undefined4 *local_8;
  
  puStack_3c = &stack0xfffffffc;
  local_2c = 0;
  local_8 = (undefined4 *)0x0;
  local_c = (byte *)0x0;
  local_10 = (byte *)0x0;
  puStack_40 = &LAB_0045ca4e;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  FUN_00403be8((int *)&local_8,0x45ca64);
  if (0 < param_1) {
    local_28 = param_1;
    FUN_0045cae8();
    local_1c = (double)in_ST0;
    local_28 = param_1;
    uVar1 = FUN_0045cb3c();
    local_28 = param_1;
    FUN_0045ca84();
    local_24 = (double)in_ST1;
    FUN_00408b38((int *)&local_c);
    iVar2 = FUN_00407f90(local_c);
    if (iVar2 < 10) {
      FUN_00403e1c((int *)&local_c,(undefined4 *)&DAT_0045ca74,(undefined4 *)local_c);
    }
    local_28 = uVar1;
    FUN_00408b38((int *)&local_10);
    iVar2 = FUN_00407f90(local_10);
    if (iVar2 < 10) {
      FUN_00403e1c((int *)&local_10,(undefined4 *)&DAT_0045ca74,(undefined4 *)local_10);
    }
    FUN_00408b38(&local_2c);
    pbStack_58 = local_10;
    FUN_00403e90((int *)&local_8,5);
  }
  FUN_00403ba4(param_2,local_8);
  *in_FS_OFFSET = pbStack_58;
  FUN_00403b50(&local_2c);
  FUN_00403b74((int *)&local_10,3);
  return;
}

