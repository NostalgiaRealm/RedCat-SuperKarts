/*
 * FUN_004049d0 at 004049d0
 * undefined __register FUN_004049d0(VARIANTARG * param_1, VARIANTARG * param_2, undefined4 param_3)
 * Address ranges: 004049d0-00404a73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004049d0(VARIANTARG *param_1,VARIANTARG *param_2,undefined4 param_3)

{
  VARTYPE VVar1;
  bool bVar2;
  uint uVar3;
  _union_2683 local_14;
  
  VVar1 = (param_1->n1).n2.vt;
  if (VVar1 == 0x100) {
    bVar2 = FUN_004049b8(param_1,(short *)param_2,param_3);
    if (!bVar2) {
      local_14._0_4_ = (uint)local_14.n2.wReserved1 << 0x10;
      uVar3 = VariantChangeTypeEx((VARIANTARG *)&local_14.n2,param_2,0x400,0,(VARTYPE)param_3);
      if (uVar3 != 0) {
        thunk_FUN_004027a0(uVar3);
      }
      FUN_0040486c(param_1);
      *(undefined4 *)&param_1->n1 = local_14._0_4_;
      *(undefined4 *)((int)&param_1->n1 + 8) = local_14._8_4_;
      *(undefined4 *)((int)&param_1->n1 + 0xc) = local_14._12_4_;
    }
  }
  else if (VVar1 == 0x101) {
    FUN_0040494c(param_1,(undefined4 *)param_2,param_3);
  }
  else {
    bVar2 = FUN_004049b8(param_1,(short *)param_2,param_3);
    if (!bVar2) {
      uVar3 = VariantChangeTypeEx(param_1,param_2,0x400,0,(VARTYPE)param_3);
      if (uVar3 != 0) {
        thunk_FUN_004027a0(uVar3);
      }
    }
  }
  return;
}

