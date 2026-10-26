/*
 * FUN_0045348c at 0045348c
 * undefined __register FUN_0045348c(int param_1, undefined4 param_2)
 * Address ranges: 0045348c-004534f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045348c(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 *extraout_ECX;
  undefined4 extraout_EDX;
  
  if (*(HGDIOBJ *)(param_1 + 0x40) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
    param_2 = extraout_EDX;
  }
  piVar2 = (int *)FUN_00453594(param_1,CONCAT31((int3)((uint)param_2 >> 8),5));
  piVar2 = (int *)FUN_0040303c(piVar2,(int)&PTR_FUN_00450238);
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x1c))();
    if (cVar1 == '\0') {
      uVar3 = FUN_00453170((int)piVar2,0,extraout_ECX);
      *(undefined4 *)(param_1 + 0x40) = uVar3;
      *(int *)(param_1 + 0x44) = piVar2[0x23];
      *(int *)(param_1 + 0x48) = piVar2[0x10];
    }
  }
  FUN_004534f4(param_1,0x4401);
  return;
}

