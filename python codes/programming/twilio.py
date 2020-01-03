from twilio import rest
def message():
    # Your Account SID from twilio.com/console
    account_sid = "AC3e4288c8901128c118c96ae7a6ac1fd6"
    # Your Auth Token from twilio.com/console
    auth_token  = "452d329097e569949361afafaa11bff9"

    client = rest.Client(account_sid, auth_token)

    message = client.messages.create(
        to="+12026880925", 
        from_="+917689961477",
        body="Hello from Python!")

    print(message.sid)

message()
