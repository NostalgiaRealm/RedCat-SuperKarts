/*
 * FUN_004bb740 at 004bb740
 * undefined FUN_004bb740(void)
 * Address ranges: 004bb740-004bb953
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bb740(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  char cStack_12;
  char cStack_11;
  int iStack_10;
  int iStack_c;
  ushort *puStack_8;
  int iStack_4;
  
  uVar2 = param_2;
  iVar3 = FUN_004bf445(param_2,&DAT_004ffff8);
  if (iVar3 == 0) {
    FUN_004afee0(s__s__d_____save_bmp__can_t_create_00502278,s_C__libraries_dxdraw_Bmp_cpp_005022a4,
                 0x3f,uVar2);
  }
  _DAT_006b5ba2 = (DAT_004fe934 * DAT_004fe930 + 0x12) * 3;
  _DAT_006b5ba0 = 0x4d42;
  _DAT_006b5ba6 = 0;
  _DAT_006b5ba8 = 0;
  _DAT_006b5baa = 0x36;
  _DAT_006b5bb0 = 0x28;
  _DAT_006b5bb4 = DAT_004fe930;
  _DAT_006b5bb8 = DAT_004fe934;
  _DAT_006b5bbc = 1;
  _DAT_006b5bbe = 0x18;
  _DAT_006b5bc0 = 0;
  _DAT_006b5bc4 = 0;
  _DAT_006b5bc8 = 0;
  _DAT_006b5bcc = 0;
  _DAT_006b5bd0 = 0;
  _DAT_006b5bd4 = 0;
  FUN_004bf31b(&DAT_006b5ba0,1,0xe,iVar3);
  FUN_004bf31b(&DAT_006b5bb0,1,0x28,iVar3);
  FUN_004b5ad0();
  iVar4 = FUN_004b0770(DAT_006a64bc,&iStack_c);
  iStack_4 = 0;
  puStack_8 = (ushort *)(iVar4 + (DAT_004fe934 + -1) * iStack_c);
  iVar4 = DAT_004fe930;
  iVar5 = DAT_004fe934;
  if (0 < DAT_004fe934) {
    do {
      iStack_10 = 0;
      puVar6 = puStack_8;
      if (0 < iVar4) {
        do {
          uVar1 = *puVar6;
          cStack_11 = (char)((int)(uVar1 & DAT_006ab7fc) >>
                            ((char)DAT_006ab7f0 + (byte)DAT_006ab7f4 & 0x1f)) <<
                      ((byte)DAT_006ab80c & 0x1f);
          cStack_12 = (char)((int)(uVar1 & DAT_006ab800) >> ((byte)DAT_006ab7f4 & 0x1f)) <<
                      ((byte)DAT_006ab810 & 0x1f);
          param_2 = CONCAT31(param_2._1_3_,
                             (DAT_006ab804 & (byte)uVar1) << ((byte)DAT_006ab814 & 0x1f));
          FUN_004bf31b(&param_2,1,1,iVar3);
          FUN_004bf31b(&cStack_12,1,1,iVar3);
          FUN_004bf31b(&cStack_11,1,1,iVar3);
          puVar6 = puVar6 + 1;
          iStack_10 = iStack_10 + 1;
          iVar4 = DAT_004fe930;
          iVar5 = DAT_004fe934;
        } while (iStack_10 < DAT_004fe930);
      }
      puStack_8 = (ushort *)((int)puStack_8 - iStack_c);
      iStack_4 = iStack_4 + 1;
    } while (iStack_4 < iVar5);
  }
  FUN_004b08a0(DAT_006a64bc,puStack_8);
  FUN_004bf2c5(iVar3);
  return;
}

