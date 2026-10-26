/*
 * FUN_00453170 at 00453170
 * undefined4 __register FUN_00453170(int param_1, uint param_2, undefined1 * param_3)
 * Address ranges: 00453170-00453239
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00453170(int param_1,uint param_2,undefined1 *param_3)

{
  int *piVar1;
  uint uVar2;
  undefined1 *extraout_ECX;
  undefined1 *puVar3;
  undefined1 *extraout_ECX_00;
  undefined1 *extraout_ECX_01;
  uint uVar4;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_14;
  
  if (param_1 != 0) {
    uVar4 = param_2 & 0xffffff;
    local_14 = *(int *)(param_1 + 0x40);
    if (-1 < local_14 + -1) {
      iVar8 = 0;
      uVar5 = uVar4;
      do {
        iVar7 = 0;
LAB_0045321e:
        if (iVar7 < *(int *)(param_1 + 0x8c)) {
          piVar1 = (int *)FUN_00451e40(param_1,uVar5,param_3);
          uVar2 = FUN_00418920(piVar1,iVar7,iVar8);
          puVar3 = extraout_ECX;
          param_3 = extraout_ECX;
          uVar5 = extraout_EDX;
          iVar6 = iVar7;
          if ((uVar2 & 0xffffff) == uVar4) {
            do {
              iVar7 = iVar7 + 1;
              if (*(int *)(param_1 + 0x8c) <= iVar7) break;
              piVar1 = (int *)FUN_00451e40(param_1,uVar5,param_3);
              uVar2 = FUN_00418920(piVar1,iVar7,iVar8);
              param_3 = extraout_ECX_01;
              uVar5 = extraout_EDX_02;
            } while ((uVar2 & 0xffffff) == uVar4);
          }
          else {
            do {
              iVar6 = iVar6 + 1;
              if (*(int *)(param_1 + 0x8c) <= iVar6) break;
              piVar1 = (int *)FUN_00451e40(param_1,uVar5,puVar3);
              uVar2 = FUN_00418920(piVar1,iVar6,iVar8);
              puVar3 = extraout_ECX_00;
              uVar5 = extraout_EDX_00;
            } while ((uVar2 & 0xffffff) != uVar4);
            param_3 = &stack0xfffffffc;
            FUN_0045312c(iVar7,iVar8,iVar6,iVar8 + 1,(int)&stack0xfffffffc);
            uVar5 = extraout_EDX_01;
            iVar7 = iVar6;
          }
          goto LAB_0045321e;
        }
        iVar8 = iVar8 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
  }
  return 0;
}

