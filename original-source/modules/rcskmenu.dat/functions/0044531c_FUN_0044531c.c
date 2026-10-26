/*
 * FUN_0044531c at 0044531c
 * undefined __register FUN_0044531c(int * param_1, int param_2, int param_3)
 * Address ranges: 0044531c-004453f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044531c(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  if ((HWND)param_1[0x53] != (HWND)0x0) {
    BVar2 = IsWindowVisible((HWND)param_1[0x53]);
    if (BVar2 != 0) {
      bVar1 = true;
      goto LAB_00445346;
    }
  }
  bVar1 = false;
LAB_00445346:
  if (bVar1) {
    ScrollWindow((HWND)param_1[0x53],param_2,param_3,(RECT *)0x0,(RECT *)0x0);
  }
  iVar3 = FUN_0044268c((int)param_1);
  if (-1 < iVar3 + -1) {
    iVar6 = 0;
    do {
      piVar4 = (int *)FUN_00442650((int)param_1,iVar6);
      uVar5 = FUN_00403024(piVar4,(int)&PTR_FUN_0043be00);
      if (((char)uVar5 == '\0') || (piVar4[0x53] == 0)) {
        piVar4[0xc] = piVar4[0xc] + param_2;
        piVar4[0xd] = piVar4[0xd] + param_3;
      }
      else if (!bVar1) {
        SetWindowPos((HWND)piVar4[0x53],(HWND)0x0,piVar4[0xc] + param_2,piVar4[0xd] + param_3,
                     piVar4[0xe],piVar4[0xf],0x14);
      }
      iVar6 = iVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_0044221c(param_1);
  return;
}

