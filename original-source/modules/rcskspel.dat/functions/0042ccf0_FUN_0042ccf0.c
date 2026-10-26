/*
 * FUN_0042ccf0 at 0042ccf0
 * undefined FUN_0042ccf0(void)
 * Address ranges: 0042ccf0-0042cde1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ccf0(void)

{
  FUN_0049f540(0);
  FUN_004a74a0(0x9c4);
  FUN_0049aec0(1000);
  FUN_004afce0(s_Initing_textures__d_004ea464,100);
  if (DAT_0053b9f0 == 0) {
    FUN_004a2d20(0x41000000);
    FUN_004a6f40(1);
  }
  FUN_004a3000(100);
  FUN_004afce0(s_loading_background_pic_004ea47c);
  if (DAT_0053b9f0 == 0) {
    FUN_004a2d90(s_init_pcx_004ea494);
    if (DAT_0053b9f0 == 0) goto LAB_0042cda9;
  }
  if (DAT_0053ba5c != 0) {
    FUN_004b5460(0);
    if (DAT_0053ba5c != 0) {
      FUN_004b5460(1);
    }
  }
  FUN_004a2cc0(1);
  FUN_004afdb0(0x7f00ff);
LAB_0042cda9:
  FUN_00429550();
  if (DAT_0053b9c8 != 0) {
    FUN_004a2d00(1);
  }
  FUN_004afce0(s_Initing_objects__d_004ea4a0,5000);
  FUN_0049f550(5000);
  FUN_0042ccd0();
  return;
}

