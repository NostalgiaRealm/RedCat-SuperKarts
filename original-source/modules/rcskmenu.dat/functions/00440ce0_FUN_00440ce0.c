/*
 * FUN_00440ce0 at 00440ce0
 * undefined FUN_00440ce0(void)
 * Address ranges: 00440ce0-00440d54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440ce0(int *param_1,int param_2)

{
  POINT pt;
  BOOL BVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  LONG LStack_24;
  LONG LStack_20;
  RECT RStack_1c;
  
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  if ((*(byte *)(param_1 + 0x10) & 2) != 0) {
    FUN_0043f868(param_1,'\0');
  }
  if ((*(byte *)(param_1 + 0x11) & 2) != 0) {
    *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) & 0xfffd;
    FUN_00406c20(*(undefined4 *)(param_2 + 8),&LStack_24);
    (**(code **)(*param_1 + 0x40))(param_1,&RStack_1c);
    pt.y = LStack_20;
    pt.x = LStack_24;
    BVar1 = PtInRect(&RStack_1c,pt);
    if (BVar1 != 0) {
      FUN_00403088(param_1,extraout_EDX,extraout_ECX);
    }
  }
  FUN_00440ca4(param_1,param_2,0);
  return;
}

