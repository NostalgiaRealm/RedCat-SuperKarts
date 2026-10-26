/*
 * FUN_0045e520 at 0045e520
 * undefined FUN_0045e520(void)
 * Address ranges: 0045e520-0045e55e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e520(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x208) != 0) {
    piVar2 = (int *)FUN_00453594(*(int *)(param_1 + 0x208),CONCAT31((int3)((uint)param_2 >> 8),6));
    cVar1 = (**(code **)(*piVar2 + 0x1c))();
    if (cVar1 == '\0') {
      *(undefined ***)(param_4 + 4) = &PTR_FUN_0045d6ec;
      *(undefined4 *)(param_4 + 0x3c) = *(undefined4 *)(param_1 + 0x208);
    }
  }
  return;
}

