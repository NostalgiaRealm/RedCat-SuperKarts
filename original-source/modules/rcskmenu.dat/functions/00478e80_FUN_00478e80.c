/*
 * FUN_00478e80 at 00478e80
 * undefined __register FUN_00478e80(int param_1, undefined4 param_2, int * param_3)
 * Address ranges: 00478e80-00478fd5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00478e80(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined *puVar9;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  int local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  int *local_c;
  int *local_8;
  
  puStack_34 = &stack0xfffffffc;
  puStack_40 = &stack0xfffffffc;
  local_c = (int *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  local_18 = 0;
  local_1c = 0;
  local_20 = (undefined4 *)0x0;
  local_24 = 0;
  puStack_38 = &LAB_00478ff8;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_44 = &LAB_00478fd6;
  uStack_48 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_48;
  uVar4 = *(undefined4 *)PTR_DAT_0047c694;
  puVar9 = &DAT_00479010;
  pcVar8 = "brief.dat";
  local_8 = param_3;
  FUN_00403e90((int *)&local_20,3);
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_20);
  uVar7 = *(undefined4 *)(PTR_PTR_0047c7dc + (uint)*(byte *)(param_1 + 0x391) * 4);
  puVar6 = &DAT_00479034;
  uVar5 = *(undefined4 *)(PTR_PTR_0047c8e8 + (uint)*(byte *)(param_1 + 0x392) * 4);
  FUN_00403e90(&local_18,3);
  (**(code **)*local_c)
            (local_c,local_18,"WELCOME",&local_1c,0,uVar5,puVar6,uVar7,pcVar8,puVar9,uVar4);
  iVar1 = (**(code **)(*local_c + 8))(local_c,local_18,"NUMLINES");
  if (0 < iVar1) {
    FUN_00403e90((int *)&local_10,3);
    if (-1 < iVar1 + -1) {
      iVar2 = 0;
      do {
        uVar4 = 0;
        ppuVar3 = &local_14;
        FUN_00407f60(iVar2,&local_24);
        (**(code **)*local_c)(local_c,local_18,local_24,ppuVar3,uVar4);
        if (local_14 == (undefined4 *)0x0) {
          FUN_00403be8((int *)&local_14,0x479070);
        }
        FUN_00403dd8((int *)&local_10,local_14);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    FUN_00403ba4(local_8,local_10);
  }
  *in_FS_OFFSET = 0;
  FUN_00402eac(local_c);
  return;
}

