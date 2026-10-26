/*
 * FUN_00455ae0 at 00455ae0
 * undefined __register FUN_00455ae0(int param_1, uint * param_2)
 * Address ranges: 00455ae0-00455bc8;00455bf1-00455c06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455ae0(int param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  bool bVar4;
  undefined4 uStackY_40;
  undefined1 *puStackY_3c;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_c;
  int local_8;
  
  puStack_20 = (undefined1 *)0x455af7;
  local_c = param_2;
  local_8 = param_1;
  FUN_00403f84((int)param_2);
  bVar4 = true;
  puStack_24 = &LAB_00455c07;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_2c = (undefined1 *)0x455b13;
  puStack_20 = &stack0xfffffffc;
  FUN_00403ee0(*(uint **)(local_8 + 0x24),local_c);
  if (!bVar4) {
    puStack_2c = (undefined1 *)0x455b27;
    FUN_00403ba4((int *)(local_8 + 0x24),local_c);
    if ((*(byte *)(local_8 + 0x20) & 0x10) != 0) {
      puStack_2c = (undefined1 *)0x455b3c;
      FUN_00455cdc(local_8);
      if (local_c != (uint *)0x0) {
        puStack_30 = &LAB_00455bda;
        uStack_34 = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStack_34;
        puStackY_3c = (undefined1 *)0x455b65;
        puStack_2c = &stack0xfffffffc;
        piVar1 = FUN_00411ab8((int *)&PTR_FUN_0040e4bc,'\x01',(undefined *)local_c,0);
        puStackY_3c = &LAB_00455bc9;
        uStackY_40 = *in_FS_OFFSET;
        *in_FS_OFFSET = &uStackY_40;
        iVar2 = FUN_004118b0(piVar1);
        *(int *)(local_8 + 0x28) = iVar2;
        uVar3 = FUN_00402714(iVar2);
        *(undefined4 *)(local_8 + 0x2c) = uVar3;
        (**(code **)(*piVar1 + 0xc))(piVar1,0,0);
        (**(code **)(*piVar1 + 4))
                  (piVar1,*(undefined4 *)(local_8 + 0x2c),*(undefined4 *)(local_8 + 0x28));
        *in_FS_OFFSET = uStackY_40;
        puStackY_3c = (undefined1 *)0x455bc8;
        FUN_00402eac(piVar1);
        return;
      }
    }
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00455c0e;
  puStack_24 = (undefined1 *)0x455c06;
  FUN_00403b50((int *)&local_c);
  return;
}

