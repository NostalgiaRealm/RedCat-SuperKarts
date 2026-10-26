/*
 * FUN_0042cc00 at 0042cc00
 * undefined FUN_0042cc00(void)
 * Address ranges: 0042cc00-0042cccd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042cc00(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_198 [26];
  int iStack_130;
  int iStack_12c;
  undefined4 local_cc [51];
  
  if (DAT_0053b9f0 == 0) {
    return 0;
  }
  FUN_004afce0(s_Checking_alpha_blending_capabali_004ea3b8);
  puVar2 = local_198;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = local_cc;
  for (iVar1 = 0x33; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_198[0] = 0xcc;
  local_cc[0] = 0xcc;
  iVar1 = (**(code **)(*DAT_006a621c + 0xc))(DAT_006a621c,local_198,local_cc);
  if (iVar1 != 0) {
    FUN_004afce0(s_Can_t_get_alpha_caps__alpha_blen_004ea3e4);
    return 0;
  }
  if ((iStack_130 == 0) && (iStack_12c == 0)) {
    FUN_004afce0(s_No_source_or_destination_alpha_b_004ea414);
    return 0;
  }
  DAT_0053ba48 = iStack_130;
  DAT_0053ba4c = iStack_12c;
  FUN_004afce0(s_Alpha_blending_supported__004ea448);
  return 1;
}

