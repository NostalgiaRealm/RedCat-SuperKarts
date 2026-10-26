/*
 * FUN_004133b0 at 004133b0
 * undefined __register FUN_004133b0(int param_1, byte * param_2, int * param_3)
 * Address ranges: 004133b0-004133e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004133b0(int param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint extraout_ECX;
  uint extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  *param_2 = 0;
  bVar1 = FUN_00412910(param_1,param_2,(uint)param_3);
  if ((bVar1 & 0xf0) == 0xf0) {
    uVar2 = FUN_004140d0(param_1,extraout_EDX,extraout_ECX);
    *param_2 = (byte)uVar2 & 0xf;
    if ((*param_2 & 2) != 0) {
      iVar3 = FUN_004132f0(param_1,extraout_EDX_00,extraout_ECX_00);
      *param_3 = iVar3;
    }
  }
  return;
}

