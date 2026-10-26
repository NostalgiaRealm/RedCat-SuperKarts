/*
 * FUN_004507f8 at 004507f8
 * int * __register FUN_004507f8(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 004507f8-004508a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004507f8(int *param_1,char param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  int iVar1;
  char extraout_DL;
  char cVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *in_FS_OFFSET;
  byte bVar7;
  undefined4 in_stack_fffffbb0;
  undefined4 in_stack_fffffbb4;
  int local_434 [12];
  undefined4 local_404 [256];
  
  bVar7 = 0;
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_fffffbb0,in_stack_fffffbb4);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00402e7c(param_1,'\0',param_3);
  *(undefined1 *)(param_1 + 0x10b) = 1;
  FUN_004503d0((undefined1 *)local_404);
  FUN_0045165c((int)param_1,local_404);
  FUN_004503d0((undefined1 *)local_404);
  puVar3 = local_404;
  puVar5 = (undefined4 *)((int)param_1 + 0x15);
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + (uint)bVar7 * -2 + 1;
    puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
  }
  FUN_004502d4(8,8,8,local_434);
  piVar4 = local_434;
  piVar6 = param_1 + 0x111;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + (uint)bVar7 * -2 + 1;
    piVar6 = piVar6 + (uint)bVar7 * -2 + 1;
  }
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_fffffbb0;
  }
  return param_1;
}

