/*
 * FUN_00455320 at 00455320
 * undefined __register FUN_00455320(int param_1, undefined * param_2)
 * Address ranges: 00455320-00455439
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455320(int param_1,undefined *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar3;
  undefined4 uVar4;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  undefined4 *local_10;
  int local_c;
  undefined4 *local_8;
  
  puStack_2c = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = 0;
  local_18 = (undefined4 *)0x0;
  local_1c = 0;
  puStack_30 = &LAB_0045543a;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  local_c = 0;
  FUN_00403b50((int *)&local_8);
  FUN_00408278(param_2,(int *)&local_10);
  FUN_00403ba4((int *)(param_1 + 0xc),local_10);
  piVar1 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',*(undefined4 **)(param_1 + 0xc));
  uVar4 = 0;
  ppuVar3 = &local_8;
  FUN_00407f60(local_c,&local_14);
  (**(code **)*piVar1)(piVar1,"transitiontable",local_14,ppuVar3,uVar4);
  FUN_00403ba4((int *)(param_1 + 8),local_8);
  (**(code **)*piVar1)(piVar1,"LASTPHASE",&DAT_00455468,&local_18,0);
  FUN_00403ba4((int *)(param_1 + 0x14),local_18);
  uVar4 = (**(code **)(*piVar1 + 8))(piVar1,"transitiontable","lastrunok");
  *(undefined4 *)(param_1 + 0x18) = uVar4;
  while( true ) {
    iVar2 = FUN_00403dd0((int)local_8);
    if (iVar2 < 1) break;
    FUN_00455498(param_1,piVar1);
    local_c = local_c + 1;
    uVar4 = 0;
    ppuVar3 = &local_8;
    FUN_00407f60(local_c,&local_1c);
    (**(code **)*piVar1)(piVar1,"transitiontable",local_1c,ppuVar3,uVar4);
  }
  FUN_00402eac(piVar1);
  *in_FS_OFFSET = 0;
  FUN_00403b74(&local_1c,4);
  FUN_00403b50((int *)&local_8);
  return;
}

