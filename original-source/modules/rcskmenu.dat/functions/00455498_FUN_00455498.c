/*
 * FUN_00455498 at 00455498
 * undefined __register FUN_00455498(int param_1, undefined4 * param_2)
 * Address ranges: 00455498-00455597
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455498(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  int unaff_ESI;
  int iVar4;
  undefined4 unaff_EDI;
  int *in_FS_OFFSET;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  int iStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int local_28;
  uint *local_24;
  undefined4 *local_20;
  
  local_20 = (undefined4 *)&stack0xfffffffc;
  iVar3 = 4;
  do {
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  LOCK();
  UNLOCK();
  local_24 = (uint *)&LAB_004555ba;
  local_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_28;
  puStack_2c = (undefined1 *)0x4554d4;
  iVar3 = FUN_00454c9c((int)&DAT_00454bf4,'\x01',(undefined4 *)0x0);
  puStack_2c = (undefined1 *)0x4554e3;
  piVar1 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  puStack_30 = &LAB_00455598;
  iStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_34;
  iVar4 = 0;
  uVar8 = 0;
  puVar7 = &stack0xffffffe8;
  puStack_2c = &stack0xfffffffc;
  FUN_00407f60(0,(int *)&stack0xffffffe4);
  (**(code **)*param_2)(param_2,0,unaff_EDI,puVar7,uVar8);
  while( true ) {
    iVar2 = FUN_00403dd0(unaff_ESI);
    if (iVar2 < 1) break;
    FUN_00454510((int)piVar1,unaff_ESI);
    FUN_0045471c((int)piVar1,1,(int *)&local_20);
    puVar6 = local_20;
    FUN_0045471c((int)piVar1,0,(int *)&local_24);
    uVar8 = FUN_0045d5e4(local_24);
    FUN_00454d60(iVar3,uVar8,puVar6);
    iVar4 = iVar4 + 1;
    uVar8 = 0;
    puVar5 = &stack0xffffffe8;
    FUN_00407f60(iVar4,&local_28);
    (**(code **)*param_2)(param_2,0,local_28,puVar5,uVar8);
  }
  FUN_00455314(param_1,iVar3);
  *in_FS_OFFSET = (int)puVar7;
  return;
}

