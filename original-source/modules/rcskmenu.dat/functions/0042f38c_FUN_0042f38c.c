/*
 * FUN_0042f38c at 0042f38c
 * undefined4 __register FUN_0042f38c(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0042f38c-0042f407
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042f38c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 uVar2;
  undefined3 uVar3;
  undefined4 extraout_ECX;
  char local_d;
  undefined4 local_c;
  int local_8;
  
  local_d = '\0';
  local_c = param_2;
  local_8 = param_1;
  if (*(short *)(param_1 + 0x2aa) != 0) {
    param_1 = (**(code **)(param_1 + 0x2a8))(*(undefined4 *)(param_1 + 0x2ac),param_2,&local_d);
    param_3 = extraout_ECX;
  }
  if (local_d == '\0') {
    piVar1 = *(int **)(local_8 + 0x230);
    if ((piVar1 != (int *)0x0) && (piVar1[0xb] != 0)) {
      param_1 = FUN_00403088(piVar1,local_c,param_3);
      if ((char)param_1 != '\0') goto LAB_0042f3fa;
    }
    param_1 = FUN_0042f338();
    if ((char)param_1 == '\0') {
      uVar2 = 0;
      uVar3 = 0;
      goto LAB_0042f3fc;
    }
  }
LAB_0042f3fa:
  uVar3 = (undefined3)((uint)param_1 >> 8);
  uVar2 = 1;
LAB_0042f3fc:
  return CONCAT31(uVar3,uVar2);
}

