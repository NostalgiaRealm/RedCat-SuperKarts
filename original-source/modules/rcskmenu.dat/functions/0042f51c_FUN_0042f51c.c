/*
 * FUN_0042f51c at 0042f51c
 * undefined __register FUN_0042f51c(int * param_1, int * param_2, undefined4 param_3)
 * Address ranges: 0042f51c-0042f5f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f51c(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  uint *local_10;
  undefined4 local_c;
  int *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_10 = (uint *)0x0;
  puStack_20 = &LAB_0042f5f5;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  local_c = param_3;
  local_8 = param_2;
  iVar2 = FUN_0044401c((int)param_1);
  if (iVar2 == 1) {
    iVar2 = FUN_0043f5c0((int)local_8);
    FUN_00403c38((int *)&local_10,(undefined4 *)0x0,iVar2 + 1);
    uVar3 = FUN_00403dd0((int)local_10);
    puVar4 = FUN_00403f94((undefined *)local_10);
    FUN_0043f5d0((int)local_8,puVar4,uVar3);
    iVar2 = FUN_00403dd0((int)local_10);
    if (0 < iVar2) {
      iVar5 = 1;
      do {
        cVar1 = *(char *)((int)local_10 + iVar5 + -1);
        if ((cVar1 == '\n') || (cVar1 == '\r')) {
          FUN_00404104((int *)&local_10,iVar5 - 1);
          break;
        }
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_0043f67c((int)param_1,local_10);
  }
  FUN_00443e90(param_1,local_8);
  FUN_0043ec64(local_8,CONCAT31((int3)((uint)extraout_EDX >> 8),5),extraout_ECX);
  if ((*(byte *)(param_1 + 8) & 1) == 0) {
    FUN_0042bbb8(param_1,CONCAT31((int3)((uint)extraout_EDX_00 >> 8),1),extraout_ECX_00);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0042f5fc;
  puStack_20 = (undefined1 *)0x42f5f4;
  FUN_00403b50((int *)&local_10);
  return;
}

