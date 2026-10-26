/*
 * FUN_0042f7b4 at 0042f7b4
 * undefined FUN_0042f7b4(void)
 * Address ranges: 0042f7b4-0042f888
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f7b4(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  uint *puStack_c;
  int *piStack_8;
  
  puStack_14 = &stack0xfffffffc;
  puStack_c = (uint *)0x0;
  puStack_18 = &LAB_0042f889;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  piStack_8 = param_1;
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  if (**(int **)(param_2 + 8) == 0xc) {
    iVar2 = FUN_0043f5c0(*(int *)(param_2 + 4));
    FUN_00403c38((int *)&puStack_c,(undefined4 *)0x0,iVar2 + 1);
    uVar3 = FUN_00403dd0((int)puStack_c);
    puVar4 = FUN_00403f94((undefined *)puStack_c);
    FUN_0043f5d0(*(int *)(param_2 + 4),puVar4,uVar3);
    iVar2 = FUN_00403dd0((int)puStack_c);
    if (0 < iVar2) {
      iVar5 = 1;
      do {
        cVar1 = *(char *)((int)puStack_c + iVar5 + -1);
        if ((cVar1 == '\n') || (cVar1 == '\r')) {
          FUN_00404104((int *)&puStack_c,iVar5 - 1);
          break;
        }
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_0043f67c((int)piStack_8,puStack_c);
  }
  else if (**(int **)(param_2 + 8) == 0xb00b) {
    FUN_0042bbb8(piStack_8,
                 CONCAT31((int3)((uint)extraout_EDX >> 8),
                          *(undefined1 *)(*(int *)(param_2 + 4) + 0x47)),extraout_ECX);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0042f890;
  puStack_18 = (undefined1 *)0x42f888;
  FUN_00403b50((int *)&puStack_c);
  return;
}

