/*
 * FUN_0044d690 at 0044d690
 * undefined __register FUN_0044d690(undefined4 * param_1, char * param_2, int param_3, int * param_4)
 * Address ranges: 0044d690-0044d776
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044d690(undefined4 *param_1,char *param_2,int param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  int *piVar4;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int local_1c [3];
  int local_10;
  char *local_c;
  undefined4 *local_8;
  
  local_1c[1] = 0;
  local_1c[0] = 0;
  puStack_2c = (undefined1 *)0x44d6b5;
  local_10 = param_3;
  local_c = param_2;
  local_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_2c = (undefined1 *)0x44d6bd;
  FUN_00403f84((int)local_c);
  puStack_2c = (undefined1 *)0x44d6c5;
  FUN_00403f84(local_10);
  puStack_30 = &LAB_0044d777;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_2c = &stack0xfffffffc;
  FUN_00403ba4(param_4,local_8);
  iVar1 = FUN_00403dd0((int)local_c);
  local_1c[2] = FUN_00403dd0(local_10);
  iVar3 = 1;
  do {
    iVar3 = FUN_0044d178(local_c,*param_4,iVar3);
    if (iVar3 != 0) {
      FUN_00403fd8(*param_4,1,iVar3 - 1,local_1c + 1);
      piVar4 = local_1c;
      uVar2 = FUN_00403dd0(*param_4);
      FUN_00403fd8(*param_4,iVar1 + iVar3,uVar2,piVar4);
      FUN_00403e90(param_4,3);
      iVar3 = iVar3 + local_1c[2];
    }
  } while (iVar3 != 0);
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_0044d77e;
  puStack_30 = (undefined1 *)0x44d769;
  FUN_00403b74(local_1c,2);
  puStack_30 = (undefined1 *)0x44d776;
  FUN_00403b74(&local_10,3);
  return;
}

