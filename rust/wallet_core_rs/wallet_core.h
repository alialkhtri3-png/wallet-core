#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * BitReader reads data from a big-endian byte slice at the granularity of a single bit.
 */
typedef struct TWBitReader TWBitReader;

/**
 * Decode function call data to human readable json format, according to input abi json.
 *
 * \param coin EVM-compatible coin type.
 * \param input The serialized data of `TW.EthereumAbi.Proto.ContractCallDecodingInput`.
 * \return serialized `EthereumAbi::Proto::ContractCallDecodingOutput`.
 */
TWData *tw_ethereum_abi_decode_contract_call(uint32_t coin, const TWData *input);

/**
 * Decode a function input or output data according to a given ABI.
 *
 * \param coin EVM-compatible coin type.
 * \param input The serialized data of `TW.EthereumAbi.Proto.ParamsDecodingInput`.
 * \return The serialized data of a `TW.EthereumAbi.Proto.ParamsDecodingOutput` proto object.
 */
TWData *tw_ethereum_abi_decode_params(uint32_t coin, const TWData *input);

/**
 * Returns the function type signature, of the form "baz(int32,uint256)".
 *
 * \param coin EVM-compatible coin type.
 * \param input The serialized data of `TW.EthereumAbi.Proto.FunctionGetTypeInput`.
 * \return function type signature as a Non-null string.
 */
TWString *tw_ethereum_abi_function_get_type(uint32_t coin, const TWData *input);

/**
 * Returns the function type signature, of the form "baz(int32,uint256)".
 *
 * \param coin EVM-compatible coin type.
 * \param abi The function ABI json string, for example: {"inputs":[{"internalType":"bool","name":"arg1","type":"bool"}],"name":"fun1","outputs":[],"stateMutability":"nonpayable","type":"function"}
 * \return function type signature, null if the input is invalid.
 */
TWString *tw_ethereum_abi_get_function_signature(uint32_t coin,
                                                 const TWString *abi);

/**
 * Encode function inputs to Eth ABI binary.
 *
 * \param coin EVM-compatible coin type.
 * \param input The serialized data of `TW.EthereumAbi.Proto.FunctionEncodingInput`.
 * \return The serialized data of a `TW.EthereumAbi.Proto.FunctionEncodingOutput` proto object.
 */
TWData *tw_ethereum_abi_encode_function(uint32_t coin, const TWData *input);

/**
 * /// Decodes an Eth ABI value according to a given type.
 *
 * \param coin EVM-compatible coin type.
 * \param input The serialized data of `TW.EthereumAbi.Proto.ValueDecodingInput`.
 * \return The serialized data of a `TW.EthereumAbi.Proto.ValueDecodingOutput` proto object.
 */
TWData *tw_ethereum_abi_decode_value(uint32_t coin, const TWData *input);

/**
 * Encodes an item or a list of items as Eth RLP binary format.
 *
 * \param coin EVM-compatible coin type.
 * \param input Non-null serialized `EthereumRlp::Proto::EncodingInput`.
 * \return serialized `EthereumRlp::Proto::EncodingOutput`.
 */
TWData *tw_ethereum_rlp_encode(uint32_t coin, const TWData *input);

/**
 * Derive default token address for token
 *
 * \param address Non-null pointer to a Solana Address
 * \param token_mint_address Non-null pointer to a token mint address as a string
 * \return Null pointer if the Default token address for a token is not found, valid pointer otherwise
 */
TWString *tw_solana_address_default_token_address(const TWString *address,
                                                  const TWString *token_mint_address);

/**
 * Derive token 2022 address for token
 *
 * \param address Non-null pointer to a Solana Address
 * \param token_mint_address Non-null pointer to a token mint address as a string
 * \return Null pointer if the token 2022 address for a token is not found, valid pointer otherwise
 */
TWString *tw_solana_address_token_2022_address(const TWString *address,
                                               const TWString *token_mint_address);

/**
 * Decode Solana transaction, update the recent blockhash and re-sign the transaction.
 *
 * # Warning
 *
 * This is a temporary solution. It will be removed when `Solana.proto` supports
 * direct transaction signing.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \param recent_blockhash base58 encoded recent blockhash.
 * \param private_keys list of private keys that should be used to re-sign the transaction.
 * \return serialized `Solana::Proto::SigningOutput`.
 */
NullableMut<TWData> tw_solana_transaction_update_blockhash_and_sign(Nonnull<TWString> encoded_tx,
                                                                    Nonnull<TWString> recent_blockhash,
                                                                    Nonnull<TWDataVector> private_keys);

/**
 * Try to find a `ComputeBudgetInstruction::SetComputeUnitPrice` instruction in the given transaction,
 * and returns the specified Unit Price.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \return nullable Unit Price as a decimal string. Null if no instruction found.
 */
NullableMut<TWString> tw_solana_transaction_get_compute_unit_price(Nonnull<TWString> encoded_tx);

/**
 * Try to find a `ComputeBudgetInstruction::SetComputeUnitLimit` instruction in the given transaction,
 * and returns the specified Unit Limit.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \return nullable Unit Limit as a decimal string. Null if no instruction found.
 */
NullableMut<TWString> tw_solana_transaction_get_compute_unit_limit(Nonnull<TWString> encoded_tx);

/**
 * Adds or updates a `ComputeBudgetInstruction::SetComputeUnitPrice` instruction of the given transaction,
 * and returns the updated transaction.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \price Unit Price as a decimal string.
 * \return base64 encoded Solana transaction. Null if an error occurred.
 */
NullableMut<TWString> tw_solana_transaction_set_compute_unit_price(Nonnull<TWString> encoded_tx,
                                                                   Nonnull<TWString> price);

/**
 * Adds or updates a `ComputeBudgetInstruction::SetComputeUnitLimit` instruction of the given transaction,
 * and returns the updated transaction.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \limit Unit Limit as a decimal string.
 * \return base64 encoded Solana transaction. Null if an error occurred.
 */
NullableMut<TWString> tw_solana_transaction_set_compute_unit_limit(Nonnull<TWString> encoded_tx,
                                                                   Nonnull<TWString> limit);

/**
 * Adds fee payer to the given transaction, and returns the updated transaction.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \param fee_payer fee payer account address. Must be a base58 encoded public key. It must NOT be in the account list yet.
 * \return base64 encoded Solana transaction. Null if an error occurred.
 */
NullableMut<TWString> tw_solana_transaction_set_fee_payer(Nonnull<TWString> encoded_tx,
                                                          Nonnull<TWString> fee_payer);

/**
 * Inserts an instruction to the given transaction at the specified position, returning the updated transaction.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \param insert_at index where the instruction should be inserted. If you don't care about the position, use -1.
 * \param instruction json encoded instruction. Here is an example: {"programId":"11111111111111111111111111111111","accounts":[{"pubkey":"YUz1AupPEy1vttBeDS7sXYZFhQJppcXMzjDiDx18Srf","isSigner":true,"isWritable":true},{"pubkey":"d8DiHEeHKdXkM2ZupT86mrvavhmJwUZjHPCzMiB5Lqb","isSigner":false,"isWritable":true}],"data":"3Bxs4Z6oyhaczjLK"}
 * \return base64 encoded Solana transaction. Null if an error occurred.
 */
NullableMut<TWString> tw_solana_transaction_insert_instruction(Nonnull<TWString> encoded_tx,
                                                               int32_t insert_at,
                                                               Nonnull<TWString> instruction);

/**
 * Inserts a SOL transfer instruction to the given transaction at the specified position, returning the updated transaction.
 * Please note that compute price and limit instructions should always be the first instructions if they are present in the transaction.
 *
 * \param encoded_tx base64 encoded Solana transaction.
 * \param insert_at index where the instruction should be inserted. If you don't care about the position, use -1.
 * \param from sender account from which the lamports will be debited.
 * \param to receiver account to which the lamports will be transferred.
 * \param lamports amount of lamports to transfer, as a decimal string.
 * \return base64 encoded Solana transaction. Null if an error occurred.
 */
NullableMut<TWString> tw_solana_transaction_insert_transfer_instruction(Nonnull<TWString> encoded_tx,
                                                                        int32_t insert_at,
                                                                        Nonnull<TWString> from,
                                                                        Nonnull<TWString> to,
                                                                        Nonnull<TWString> lamports);

/**
 * Converts a TON user address into a Bag of Cells (BoC) with a single root Cell.
 * The function is mostly used to request a Jetton user address via `get_wallet_address` RPC.
 * https://docs.ton.org/develop/dapps/asset-processing/jettons#retrieving-jetton-wallet-addresses-for-a-given-user
 *
 * \param address Address to be converted into a Bag Of Cells (BoC).
 * \return Pointer to a base64 encoded Bag Of Cells (BoC). Null if invalid address provided.
 */
NullableMut<TWString> tw_ton_address_converter_to_boc(Nonnull<TWString> address);

/**
 * Parses a TON address from a Bag of Cells (BoC) with a single root Cell.
 * The function is mostly used to parse a Jetton user address received on `get_wallet_address` RPC.
 * https://docs.ton.org/develop/dapps/asset-processing/jettons#retrieving-jetton-wallet-addresses-for-a-given-user
 *
 * \param boc Base64 encoded Bag Of Cells (BoC).
 * \return Pointer to a Jetton address.
 */
NullableMut<TWString> tw_ton_address_converter_from_boc(Nonnull<TWString> boc);

/**
 * Converts any TON address format to user friendly with the given parameters.
 *
 * \param address raw or user-friendly address to be converted.
 * \param bounceable whether the result address should be bounceable.
 * \param testnet whether the result address should be testnet.
 * \return user-friendly address str.
 */
NullableMut<TWString> tw_ton_address_converter_to_user_friendly(Nonnull<TWString> address,
                                                                bool bounceable,
                                                                bool testnet);

/**
 * Signs an arbitrary message to prove ownership of an address for off-chain services.
 * https://github.com/ton-foundation/specs/blob/main/specs/wtf-0002.md
 *
 * \param private_key: the private key used for signing
 * \param message: A custom message which is input to the signing.
 * \returns the signature, Hex-encoded. On invalid input null is returned. Returned object needs to be deleted after use.
 */
NullableMut<TWString> tw_ton_message_signer_sign_message(Nonnull<TWPrivateKey> private_key,
                                                         Nonnull<TWString> message);

/**
 * Constructs a TON Wallet V4R2 stateInit encoded as BoC (BagOfCells) for the given `public_key`.
 *
 * \param public_key wallet's public key.
 * \param workchain TON workchain to which the wallet belongs. Usually, base chain is used (0).
 * \param wallet_id wallet's ID allows to create multiple wallets for the same private key.
 * \return Pointer to a base64 encoded Bag Of Cells (BoC) StateInit. Null if invalid public key provided.
 */
NullableMut<TWString> tw_ton_wallet_build_v4_r2_state_init(Nonnull<TWPublicKey> public_key,
                                                           int32_t workchain,
                                                           int32_t wallet_id);

/**
 *
 * \param public_key wallet's public key.
 * \param workchain TON workchain to which the wallet belongs. Usually, base chain is used (0).
 * \param wallet_id wallet's ID allows to create multiple wallets for the same private key.
 * \return Pointer to a base64 encoded Bag Of Cells (BoC) StateInit. Null if invalid public key provided.
 */
NullableMut<TWString> tw_ton_wallet_build_v5_r1_state_init(Nonnull<TWPublicKey> public_key,
                                                           int32_t workchain,
                                                           int32_t wallet_id);

/**
 * Constructs a new `TWBitReader` from a big-endian byte slice
 * that will not allow reading more than `bit_len` bits. It must be deleted at the end.
 *
 * \param data big-endian byte slice to be read.
 * \param bit_len length this reader is allowed to read from the slice.
 * \return nullable pointer to a `TWBitReader` instance.
 */
struct TWBitReader *tw_bit_reader_create(const TWData *data, uint64_t bit_len);

/**
 * Deletes a `TWBitReader` and frees the memory.
 * \param reader a `TWBitReader` pointer.
 */
void tw_bit_reader_delete(struct TWBitReader *reader);

/**
 * Read at most 8 bits into a u8.
 *
 * \param reader a `TWBitReader` pointer.
 * \param bit_count number of bits to read. Expected from 1 to 8.
 * \return u8 or error.
 */
CUInt8Result tw_bit_reader_read_u8(struct TWBitReader *reader, uint8_t bit_count);

/**
 * Reads an entire slice of `byteCount` bytes. If there aren't enough bits remaining
 * after the internal cursor's current position, returns null.
 *
 * \param reader a `TWBitReader` pointer.
 * \param byte_count number of bytes to read.
 * \return byte array or error.
 */
CByteArrayResult tw_bit_reader_read_u8_slice(struct TWBitReader *reader, uintptr_t byte_count);

/**
 * Checks whether all bits were read.
 *
 * \param reader a `TWBitReader` pointer.
 * \return whether all bits were read.
 */
bool tw_bit_reader_finished(const struct TWBitReader *reader);

/**
 * Creates a random UUID.
 * This uses the [`getrandom`] crate to utilise the operating system's RNG
 * as the source of random numbers.
 */
char *tw_uuid_random(void);

char *tw_identity_engine_status(void);

void tw_identity_string_free(char *ptr);
