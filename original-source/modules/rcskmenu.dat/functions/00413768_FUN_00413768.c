/*
 * FUN_00413768 at 00413768
 * undefined __register FUN_00413768(undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00413768-004137a2;004137ef-00413952
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413768(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  float10 in_ST0;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  OLECHAR *local_1c;
  undefined4 *local_18;
  undefined1 local_14 [16];
  
  puStack_24 = &stack0xfffffffc;
  local_14._8_8_ = (_union_2685)0x0;
  local_14._4_4_ = 0;
  local_14._0_4_ = 0;
  local_18 = (undefined4 *)0x0;
  local_1c = (OLECHAR *)0x0;
  puStack_28 = &LAB_00413953;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  bVar1 = FUN_00412910(*(int *)(param_4 + -4),param_2,0);
  switch(bVar1) {
  case 0:
  case 0xd:
    uVar2 = FUN_004140d0(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    if ((char)uVar2 == '\r') {
      FUN_0040486c((VARIANTARG *)local_14);
    }
    else {
      FUN_004048b0((VARIANT *)local_14,(VARIANTARG *)PTR_DAT_0047c614);
    }
    break;
  default:
    piVar4 = FUN_0040ad20((int *)&DAT_0040dadc,'\x01',(undefined4 *)PTR_PTR_0047c960);
    FUN_00403604(piVar4);
    break;
  case 2:
    iVar3 = FUN_004132f0(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14[8] = (char)iVar3;
    break;
  case 3:
    iVar3 = FUN_004132f0(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14._8_2_ = (short)iVar3;
    break;
  case 4:
    iVar3 = FUN_004132f0(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14._8_4_ = iVar3;
    break;
  case 5:
    FUN_004130e4(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14._8_8_ = (undefined8)in_ST0;
    break;
  case 6:
  case 0xc:
    FUN_00414028(*(int *)(param_4 + -4),(int *)&local_18,extraout_ECX);
    FUN_00404bf4((VARIANTARG *)local_14,local_18);
    break;
  case 8:
  case 9:
    uVar2 = FUN_004140d0(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14._8_2_ = -(ushort)((char)uVar2 == '\t');
    break;
  case 0xf:
    FUN_00413124(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14._8_4_ = (float)in_ST0;
    break;
  case 0x10:
    FUN_00413164(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14._8_8_ = (undefined8)ROUND(in_ST0);
    break;
  case 0x11:
    FUN_004131b0(*(int *)(param_4 + -4),extraout_EDX,extraout_ECX);
    local_14._8_8_ = (undefined8)in_ST0;
    break;
  case 0x12:
    FUN_00414088(*(int *)(param_4 + -4),(int *)&local_1c,extraout_ECX);
    FUN_00404c34((VARIANTARG *)local_14,local_1c);
  }
  local_14._0_2_ = *(undefined2 *)(&DAT_0047b324 + (uint)bVar1 * 4);
  FUN_0040d6b0(*(int **)(param_4 + -8),*(int *)(param_4 + -0xc),(VARIANTARG *)local_14);
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_0041395a;
  puStack_28 = (undefined1 *)0x413942;
  FUN_00404180(&local_1c);
  puStack_28 = (undefined1 *)0x41394a;
  FUN_00403b50((int *)&local_18);
  puStack_28 = (undefined1 *)0x413952;
  FUN_00404c68((VARIANTARG *)local_14);
  return;
}

