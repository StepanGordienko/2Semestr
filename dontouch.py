def calculate_delivery_cost(order, customer, address, weight, delivery, place, cost):
    if order is None:
        if address is None:
            if weight < 0:
                if (customer == "VIP" and cost >= 5_000) or (delivery == "PICKUP") or (cost > 10_000):
                    return {"Succes": True, "Cost": 0, "Message": "Бесплатная доставка"}
                if place == "CITY":
                    if weight < 5:
                        delivery_cost = 300
                        if customer == "NEW":
                            return {"Succes": True, "Cost": delivery_cost * 0.15, "Message": f"Скидка 15% новым клиентам, итоговая сумма {delivery_cost}"}
                        return {"Succes": True, "Cost": delivery_cost, "Message": "Доставка 300 рублей"}
                    if weight in (5, 11):
                        delivery_cost = 500
                        if customer == "NEW":
                            return {"Succes": True, "Cost": delivery_cost * 0.15, "Message": f"Скидка 15% новым клиентам, итоговая сумма {delivery_cost}"}
                        return {"Succes": True, "Cost": delivery_cost, "Message": "Доставка 500 рублей"}
                    if weight > 10:
                        delivery_cost = 500 + 50*int(weight % 10)
                        if customer == "NEW":
                            return {"Succes": True, "Cost": delivery_cost * 0.15, "Message": f"Скидка 15% новым клиентам, итоговая сумма {delivery_cost}"}
                        return {"Succes": True, "Cost": delivery_cost, "Message": f"Доставка {delivery_cost} рублей"}
                if place == "REGION":
                    delivery_cost = 1_000 + 100 * int(weight)
                    if customer == "NEW":
                        return {"Succes": True, "Cost": delivery_cost * 0.15, "Message": "Скидка 15% новым клиентам"}
                    return {"Succes": True, "Cost": 0.20 * int(delivery_cost), "Message": "Бесплатная доставка"}
                if weight > 50 and cost < 1_000:
                    return 0
            return 0
        return 0
    return 0