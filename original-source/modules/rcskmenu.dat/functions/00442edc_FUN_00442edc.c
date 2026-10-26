/*
 * FUN_00442edc at 00442edc
 * undefined __register FUN_00442edc(int * param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00442edc-00442f91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442edc(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  POINT pt;
  bool bVar1;
  char cVar2;
  BOOL BVar3;
  undefined4 uVar4;
  int iVar5;
  LONG LVar6;
  LONG LVar7;
  RECT local_1c;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_0040ebd0(**(int **)(param_4 + -4) - param_1[0xc],
               *(int *)(*(int *)(param_4 + -4) + 4) - param_1[0xd],&local_c);
  *(undefined4 *)(param_4 + -0xc) = local_c;
  *(undefined4 *)(param_4 + -8) = local_8;
  LVar7 = *(LONG *)(param_4 + -8);
  LVar6 = *(LONG *)(param_4 + -0xc);
  (**(code **)(*param_1 + 0x40))(param_1,&local_1c);
  pt.y = LVar7;
  pt.x = LVar6;
  BVar3 = PtInRect(&local_1c,pt);
  if (BVar3 != 0) {
    if (((*(byte *)(param_1 + 8) & 0x10) != 0) &&
       ((*(char *)((int)param_1 + 0x47) != '\0' || ((*(byte *)((int)param_1 + 0x41) & 4) == 0)))) {
LAB_00442f81:
      bVar1 = true;
      goto LAB_00442f83;
    }
    if (*(char *)((int)param_1 + 0x47) != '\0') {
      cVar2 = (**(code **)(*param_1 + 0x4c))();
      if ((cVar2 != '\0') || (*(char *)(param_4 + -0xd) != '\0')) {
        uVar4 = FUN_00406c34((undefined2 *)(param_4 + -0xc));
        iVar5 = FUN_004405f0((int)param_1,0xb00a,0,uVar4);
        if (iVar5 != 0) goto LAB_00442f81;
      }
    }
  }
  bVar1 = false;
LAB_00442f83:
  if (bVar1) {
    *(int **)(param_4 + -0x14) = param_1;
  }
  return;
}

