/*
 * FUN_004b5ad0 at 004b5ad0
 * undefined FUN_004b5ad0(void)
 * Address ranges: 004b5ad0-004b5c12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b5ad0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  FUN_004b08e0(DAT_006a64bc);
  puVar4 = &DAT_006ab7c8;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  DAT_006ab7c8 = 0x20;
  iVar3 = (**(code **)(*DAT_006a64bc + 0x54))(DAT_006a64bc,&DAT_006ab7c8);
  if (iVar3 != 0) {
    uVar1 = FUN_004b0190(iVar3);
    FUN_004afee0(s__s__d____unable_to_get_pixelform_00500be4,
                 s_C__libraries_dxdraw_Pformat_cpp_00500af4,0x264,uVar1);
  }
  if (((byte)DAT_006ab7cc & 0x20) == 0) {
    DAT_006ab81c = 0;
    for (uVar2 = DAT_006ab7d8; (uVar2 & 1) == 0; uVar2 = (int)uVar2 >> 1) {
      DAT_006ab81c = DAT_006ab81c + 1;
    }
    DAT_006ab7ec = 0;
    for (; (uVar2 & 1) != 0; uVar2 = (int)uVar2 >> 1) {
      DAT_006ab7ec = DAT_006ab7ec + 1;
    }
    DAT_006ab7fc = DAT_006ab7d8;
    DAT_006ab80c = 8 - DAT_006ab7ec;
    DAT_006ab820 = 0;
    for (uVar2 = DAT_006ab7dc; (uVar2 & 1) == 0; uVar2 = (int)uVar2 >> 1) {
      DAT_006ab820 = DAT_006ab820 + 1;
    }
    DAT_006ab7f0 = 0;
    for (; (uVar2 & 1) != 0; uVar2 = (int)uVar2 >> 1) {
      DAT_006ab7f0 = DAT_006ab7f0 + 1;
    }
    DAT_006ab800 = DAT_006ab7dc;
    DAT_006ab810 = 8 - DAT_006ab7f0;
    DAT_006ab824 = 0;
    for (uVar2 = DAT_006ab7e0; (uVar2 & 1) == 0; uVar2 = (int)uVar2 >> 1) {
      DAT_006ab824 = DAT_006ab824 + 1;
    }
    DAT_006ab7f4 = 0;
    for (; (uVar2 & 1) != 0; uVar2 = (int)uVar2 >> 1) {
      DAT_006ab7f4 = DAT_006ab7f4 + 1;
    }
    _DAT_006ab804 = DAT_006ab7e0;
    DAT_006ab814 = 8 - DAT_006ab7f4;
    DAT_006ab7e8 = 1;
    return;
  }
  DAT_006ab7e8 = 1;
  DAT_006ab82c = 0;
  return;
}

