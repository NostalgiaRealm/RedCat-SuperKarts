/*
 * FUN_0044e4f8 at 0044e4f8
 * undefined __register FUN_0044e4f8(undefined4 * param_1, byte * param_2, int param_3, int * param_4)
 * Address ranges: 0044e4f8-0044e5f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e4f8(undefined4 *param_1,byte *param_2,int param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *in_FS_OFFSET;
  char *pcVar4;
  int *piVar5;
  char *local_24;
  char *local_20;
  int local_1c;
  int local_18;
  char *local_14;
  char *local_10;
  int local_c;
  byte *local_8;
  
  local_10 = (char *)0x0;
  local_14 = (char *)0x0;
  local_18 = 0;
  local_1c = 0;
  local_20 = (char *)0x0;
  local_24 = (char *)0x0;
  local_c = param_3;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  FUN_00403f84(local_c);
  iVar3 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&stack0xffffffc8;
  FUN_00403ba4(param_4,param_1);
  FUN_00407ca8((byte *)*param_4,(int *)&local_10);
  pcVar4 = local_10;
  FUN_00407ca8(local_8,(int *)&local_14);
  iVar1 = FUN_004040bc(local_14,pcVar4);
  while (iVar1 != 0) {
    FUN_00403fd8(*param_4,1,iVar1 - 1,&local_18);
    piVar5 = &local_1c;
    uVar2 = FUN_00403dd0(*param_4);
    iVar3 = FUN_00403dd0((int)local_8);
    FUN_00403fd8(*param_4,iVar3 + iVar1,uVar2,piVar5);
    iVar3 = local_1c;
    FUN_00403e90(param_4,3);
    FUN_00407ca8((byte *)*param_4,(int *)&local_20);
    pcVar4 = local_20;
    FUN_00407ca8(local_8,(int *)&local_24);
    iVar1 = FUN_004040bc(local_24,pcVar4);
  }
  *in_FS_OFFSET = iVar3;
  FUN_00403b74((int *)&local_24,8);
  return;
}

