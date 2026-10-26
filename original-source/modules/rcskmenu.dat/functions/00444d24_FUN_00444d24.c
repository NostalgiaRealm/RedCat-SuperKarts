/*
 * FUN_00444d24 at 00444d24
 * undefined __register FUN_00444d24(int * param_1)
 * Address ranges: 00444d24-00444d5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444d24(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar3;
  undefined4 uVar4;
  
  FUN_00440eb8(param_1);
  bVar1 = FUN_00445a20((int)param_1);
  uVar3 = extraout_var;
  if (bVar1) {
    uVar4 = 0;
    uVar2 = FUN_004176e4(param_1[0x16]);
    FUN_004405f0((int)param_1,0x30,uVar2,uVar4);
    uVar3 = extraout_var_00;
  }
  FUN_004426ec((int)param_1,CONCAT22(uVar3,0xb008));
  return;
}

